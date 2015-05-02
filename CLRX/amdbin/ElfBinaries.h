/*
 *  CLRadeonExtender - Unofficial OpenCL Radeon Extensions Library
 *  Copyright (C) 2014-2015 Mateusz Szpakowski
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
/*! \file ElfBinaries.h
 * \brief Elf binaries handling
 */

#ifndef __CLRX_ELFBINARIES_H__
#define __CLRX_ELFBINARIES_H__

#include <CLRX/Config.h>
#include <elf.h>
#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <ostream>
#include <CLRX/utils/MemAccess.h>
#include <CLRX/utils/Utilities.h>
#include <CLRX/utils/Containers.h>

/* INFO: in this file is used ULEV function for conversion
 * from LittleEndian and unaligned access to other memory access policy and endianness
 * Please use this function whenever you want to get or set word in ELF binary,
 * because ELF binaries can be unaligned in memory (as inner binaries).
 */

/// main namespace
namespace CLRX
{

enum : cxuint {
    ELF_CREATE_SECTIONMAP = 1,  ///< create map of sections
    ELF_CREATE_SYMBOLMAP = 2,   ///< create map of symbols
    ELF_CREATE_DYNSYMMAP = 4,   ///< create map of dynamic symbols
    ELF_CREATE_ALL = 0xf, ///< creation flags for ELF binaries
};

struct Elf32Types
{
    typedef uint32_t Size;
    typedef uint32_t Word;
    typedef Elf32_Ehdr Ehdr;
    typedef Elf32_Shdr Shdr;
    typedef Elf32_Phdr Phdr;
    typedef Elf32_Sym Sym;
    static const cxbyte ELFCLASS;
    static const cxuint bitness;
    static const char* bitName;
};

struct Elf64Types
{
    typedef size_t Size;
    typedef uint64_t Word;
    typedef Elf64_Ehdr Ehdr;
    typedef Elf64_Shdr Shdr;
    typedef Elf64_Phdr Phdr;
    typedef Elf64_Sym Sym;
    static const cxbyte ELFCLASS;
    static const cxuint bitness;
    static const char* bitName;
};

/// ELF binary class
/** This object doesn't copy binary code content.
 * Only it takes and uses a binary code.
 */
template<typename Types>
class ElfBinaryTemplate
{
public:
    /// section index map
    typedef Array<std::pair<const char*, size_t> > SectionIndexMap;
    /// symbol index map
    typedef Array<std::pair<const char*, size_t> > SymbolIndexMap;
protected:
    cxuint creationFlags;   ///< creation flags holder
    size_t binaryCodeSize;  ///< binary code size
    cxbyte* binaryCode;       ///< pointer to binary code
    cxbyte* sectionStringTable;   ///< pointer to section's string table
    cxbyte* symbolStringTable;    ///< pointer to symbol's string table
    cxbyte* symbolTable;          ///< pointer to symbol table
    cxbyte* dynSymStringTable;    ///< pointer to dynamic symbol's string table
    cxbyte* dynSymTable;          ///< pointer to dynamic symbol table
    SectionIndexMap sectionIndexMap;    ///< section's index map
    SymbolIndexMap symbolIndexMap;      ///< symbol's index map
    SymbolIndexMap dynSymIndexMap;      ///< dynamic symbol's index map
    
    typename Types::Size symbolsNum;    ///< symbols number
    typename Types::Size dynSymbolsNum; ///< dynamic symbols number
    uint16_t symbolEntSize; ///< symbol entry size in a symbol's table
    uint16_t dynSymEntSize; ///< dynamic symbol entry size in a dynamic symbol's table
    
public:
    ElfBinaryTemplate();
    /** constructor.
     * \param binaryCodeSize binary code size
     * \param binaryCode pointer to binary code
     * \param creationFlags flags that specified what will be created during creation
     */
    ElfBinaryTemplate(size_t binaryCodeSize, cxbyte* binaryCode,
                cxuint creationFlags = ELF_CREATE_ALL);
    virtual ~ElfBinaryTemplate();
    
    /// get creation flags
    cxuint getCreationFlags() const
    { return creationFlags; }
    
    /// returns true if object has a section's index map
    bool hasSectionMap() const
    { return (creationFlags & ELF_CREATE_SECTIONMAP) != 0; }
    
    /// returns true if object has a symbol's index map
    bool hasSymbolMap() const
    { return (creationFlags & ELF_CREATE_SYMBOLMAP) != 0; }
    
    /// returns true if object has a dynamic symbol's index map
    bool hasDynSymbolMap() const
    { return (creationFlags & ELF_CREATE_DYNSYMMAP) != 0; }
    
    /// get size of binaries
    size_t getSize() const
    { return binaryCodeSize; }
    
    /// returns true if object is initialized
    operator bool() const
    { return binaryCode!=nullptr; }
    
    /// returns true if object is uninitialized
    bool operator!() const
    { return binaryCode==nullptr; }
    
    const cxbyte* getBinaryCode() const
    { return binaryCode; }
    
    cxbyte* getBinaryCode()
    { return binaryCode; }
    
    /// get ELF binary header
    const typename Types::Ehdr& getHeader() const
    { return *reinterpret_cast<const typename Types::Ehdr*>(binaryCode); }
    
    /// get ELF binary header
    typename Types::Ehdr& getHeader()
    { return *reinterpret_cast<typename Types::Ehdr*>(binaryCode); }
    
    /// get section headers number
    uint16_t getSectionHeadersNum() const
    { return ULEV(getHeader().e_shnum); }
    
    /// get section header with specified index
    const typename Types::Shdr& getSectionHeader(uint16_t index) const
    {
        const typename Types::Ehdr& ehdr = getHeader();
        return *reinterpret_cast<const typename Types::Shdr*>(binaryCode +
                ULEV(ehdr.e_shoff) + size_t(ULEV(ehdr.e_shentsize))*index);
    }
    
    /// get section header with specified index
    typename Types::Shdr& getSectionHeader(uint16_t index)
    {
        const typename Types::Ehdr& ehdr = getHeader();
        return *reinterpret_cast<typename Types::Shdr*>(binaryCode +
                ULEV(ehdr.e_shoff) + size_t(ULEV(ehdr.e_shentsize))*index);
    }
    
    /// get program headers number
    uint16_t getProgramHeadersNum() const
    { return ULEV(getHeader().e_phnum); }
    
    /// get program header with specified index
    const typename Types::Phdr& getProgramHeader(uint16_t index) const
    {
        const typename Types::Ehdr& ehdr = getHeader();
        return *reinterpret_cast<const typename Types::Phdr*>(binaryCode +
                ULEV(ehdr.e_phoff) + size_t(ULEV(ehdr.e_phentsize))*index);
    }
    
    /// get program header with specified index
    typename Types::Phdr& getProgramHeader(uint16_t index)
    {
        const typename Types::Ehdr& ehdr = getHeader();
        return *reinterpret_cast<typename Types::Phdr*>(binaryCode +
                ULEV(ehdr.e_phoff) + size_t(ULEV(ehdr.e_phentsize))*index);
    }
    
    /// get symbols number
    typename Types::Size getSymbolsNum() const
    { return symbolsNum; }
    
    /// get dynamic symbols number
    typename Types::Size getDynSymbolsNum() const
    { return dynSymbolsNum; }
    
    /// get symbol with specified index
    const typename Types::Sym& getSymbol(typename Types::Size index) const
    {
        return *reinterpret_cast<const typename Types::Sym*>(symbolTable +
                    size_t(index)*symbolEntSize);
    }
    
    /// get symbol with specified index
    typename Types::Sym& getSymbol(typename Types::Size index)
    {
        return *reinterpret_cast<typename Types::Sym*>(
            symbolTable + size_t(index)*symbolEntSize);
    }
    
    /// get dynamic symbol with specified index
    const typename Types::Sym& getDynSymbol(typename Types::Size index) const
    {
        return *reinterpret_cast<const typename Types::Sym*>(dynSymTable +
            size_t(index)*dynSymEntSize);
    }
    
    /// get dynamic symbol with specified index
    typename Types::Sym& getDynSymbol(typename Types::Size index)
    {
        return *reinterpret_cast<typename Types::Sym*>(dynSymTable +
            size_t(index)*dynSymEntSize);
    }
    
    /// get symbol name with specified index
    const char* getSymbolName(typename Types::Size index) const
    {
        const typename Types::Sym& sym = getSymbol(index);
        return reinterpret_cast<const char*>(symbolStringTable + ULEV(sym.st_name));
    }
    
    /// get dynamic symbol name with specified index
    const char* getDynSymbolName(typename Types::Size index) const
    {
        const typename Types::Sym& sym = getDynSymbol(index);
        return reinterpret_cast<const char*>(dynSymStringTable + ULEV(sym.st_name));
    }
    
    /// get section name with specified index
    const char* getSectionName(uint16_t index) const
    {
        const typename Types::Shdr& section = getSectionHeader(index);
        return reinterpret_cast<const char*>(sectionStringTable + ULEV(section.sh_name));
    }
    
    /// get end iterator if section index map
    SectionIndexMap::const_iterator getSectionIterEnd() const
    { return sectionIndexMap.end(); }
    
    /// get section iterator with specified name (requires section index map)
    SectionIndexMap::const_iterator getSectionIter(const char* name) const
    {
        SectionIndexMap::const_iterator it = binaryMapFind(
                    sectionIndexMap.begin(), sectionIndexMap.end(), name, CStringLess());
        if (it == sectionIndexMap.end())
            throw Exception(std::string("Can't find Elf")+Types::bitName+" Section");
        return it;
    }
    
    /// get section index with specified name
    uint16_t getSectionIndex(const char* name) const;
    
    /// get symbol index with specified name (requires symbol index map)
    typename Types::Size getSymbolIndex(const char* name) const;
    
    /// get dynamic symbol index with specified name (requires dynamic symbol index map)
    typename Types::Size getDynSymbolIndex(const char* name) const;
    
    /// get end iterator of symbol index map
    SymbolIndexMap::const_iterator getSymbolIterEnd() const
    { return symbolIndexMap.end(); }
    
    /// get end iterator of dynamic symbol index map
    SymbolIndexMap::const_iterator getDynSymbolIterEnd() const
    { return dynSymIndexMap.end(); }
    
    /// get symbol iterator with specified name (requires symbol index map)
    SymbolIndexMap::const_iterator getSymbolIter(const char* name) const
    {
        SymbolIndexMap::const_iterator it = binaryMapFind(
                    symbolIndexMap.begin(), symbolIndexMap.end(), name, CStringLess());
        if (it == symbolIndexMap.end())
            throw Exception(std::string("Can't find Elf")+Types::bitName+" Symbol");
        return it;
    }

    /// get dynamic symbol iterator with specified name (requires dynamic symbol index map)
    SymbolIndexMap::const_iterator getDynSymbolIter(const char* name) const
    {
        SymbolIndexMap::const_iterator it = binaryMapFind(
                    dynSymIndexMap.begin(), dynSymIndexMap.end(), name, CStringLess());
        if (it == dynSymIndexMap.end())
            throw Exception(std::string("Can't find Elf")+Types::bitName+" DynSymbol");
        return it;
    }
    
    /// get section header with specified name
    const typename Types::Shdr& getSectionHeader(const char* name) const
    { return getSectionHeader(getSectionIndex(name)); }
    
    /// get section header with specified name
    typename Types::Shdr& getSectionHeader(const char* name)
    { return getSectionHeader(getSectionIndex(name)); }
    
    /// get symbol with specified name (requires symbol index map)
    const typename Types::Sym& getSymbol(const char* name) const
    { return getSymbol(getSymbolIndex(name)); }
    
    /// get symbol with specified name (requires symbol index map)
    typename Types::Sym& getSymbol(const char* name)
    { return getSymbol(getSymbolIndex(name)); }
    
    /// get dynamic symbol with specified name (requires dynamic symbol index map)
    const typename Types::Sym& getDynSymbol(const char* name) const
    { return getDynSymbol(getDynSymbolIndex(name)); }
    
    /// get dynamic symbol with specified name (requires dynamic symbol index map)
    typename Types::Sym& getDynSymbol(const char* name)
    { return getDynSymbol(getDynSymbolIndex(name)); }
    
    /// get section content pointer
    const cxbyte* getSectionContent(uint16_t index) const
    {
        const typename Types::Shdr& shdr = getSectionHeader(index);
        return binaryCode + ULEV(shdr.sh_offset);
    }
    
    /// get section content pointer
    cxbyte* getSectionContent(uint16_t index)
    {
        typename Types::Shdr& shdr = getSectionHeader(index);
        return binaryCode + ULEV(shdr.sh_offset);
    }
    
    /// get section content pointer
    const cxbyte* getSectionContent(const char* name) const
    {  return getSectionContent(getSectionIndex(name)); }
    
    /// get section content pointer
    cxbyte* getSectionContent(const char* name)
    {  return getSectionContent(getSectionIndex(name)); }
};

extern template class ElfBinaryTemplate<Elf32Types>;
extern template class ElfBinaryTemplate<Elf64Types>;

/// type for 32-bit ELF binary
typedef class ElfBinaryTemplate<Elf32Types> ElfBinary32;
/// type for 64-bit ELF binary
typedef class ElfBinaryTemplate<Elf64Types> ElfBinary64;

/// elf binary generator template
template<typename Types>
class ElfBinaryGenTemplate
{
private:
    std::unique_ptr<typename Types::Size[]> programOffsets;
    std::unique_ptr<typename Types::Size[]> sectionOffsets;
    
protected:
    void prepare();
    
    /// write section header string table section to stream
    void writeShStrTabSectionContent(std::ostream& os) const;
    
    /// get size of section header string table section
    typename Types::Size getShStrTabSectionSize() const;
    
    /// write symbol table section to stream
    void writeSymTabSectionContent(std::ostream& os) const;
    
    /// get size of symbol table section 
    typename Types::Size getSymTabSectionSize() const;
    
    /// write symbol string table section to stream
    void writeStrTabSectionContent(std::ostream& os) const;
    
    /// get size of symbol string table section 
    typename Types::Size getStrTabSectionSize() const;
    
    /// write dynamic symbol table section to stream
    void writeDynSymSectionContent(std::ostream& os) const;
    
    /// get size of dynamic symbol table section to stream
    typename Types::Size getDynSymSectionSize() const;
    
    /// write dynamic  symbol string table section to stream
    void writeDynStrSectionContent(std::ostream& os) const;
    
    /// get size of dynamic symbol table section to stream
    typename Types::Size getDynStrSectionSize() const;
    
    /// get elf header
    virtual typename Types::Ehdr getHeader() const = 0;
    
    /// get section headers count
    virtual uint16_t getSectionHeadersCount() const = 0;
    
    /// get get section header
    virtual typename Types::Shdr getSectionHeader(uint16_t sectionId) const = 0;
    
    /// write section to stream
    virtual void writeSectionContent(uint16_t sectionId, std::ostream& os) const = 0;
    
    /// get section name
    virtual const char* getSectionName(uint16_t sectionId) const = 0;
    
    /// get program headers count
    virtual uint16_t getProgramHeadersCount() const = 0;
    
    /// get program header
    virtual typename Types::Phdr getProgramHeader(uint16_t phdrId) const = 0;
    
    /// write unused space in binary (for example between sections)
    virtual void writeUnusedSpace(typename Types::Size offset, typename Types::Size size,
                std::ostream& os) const;
    
    /// get symbol count
    virtual typename Types::Size getSymbolsCount() const = 0;
    
    /// get symbol
    virtual typename Types::Sym getSymbol(typename Types::Size symbolId) const = 0;
    
    /// get symbol name
    virtual const char* getSymbolName(typename Types::Size symbolId) const = 0;
    
    /// get dynamic symbol count
    virtual typename Types::Size getDynSymbolsCount() const = 0;
    
    /// get dynamic symbol
    virtual typename Types::Sym getDynSymbol(typename Types::Size symbolId) const = 0;
    
    /// get dynamic symbol count
    virtual const char* getDynSymbolName(typename Types::Size symbolId) const = 0;
public:
    virtual ~ElfBinaryGenTemplate();
    
    size_t generateSize() const;
    void generate(std::ostream& os) const;
};

/// type for 32-bit ELF binary generator
typedef class ElfBinaryGenTemplate<Elf32Types> ElfBinary32Generator;
/// type for 64-bit ELF binary generator
typedef class ElfBinaryGenTemplate<Elf64Types> ElfBinary64Generator;

}

#endif

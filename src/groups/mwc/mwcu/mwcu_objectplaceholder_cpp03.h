// Copyright 2022-2023 Bloomberg Finance L.P.
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// mwcu_objectplaceholder_cpp03.h                                     -*-C++-*-

// Automatically generated file.  **DO NOT EDIT**

#ifndef INCLUDED_MWCU_OBJECTPLACEHOLDER_CPP03
#define INCLUDED_MWCU_OBJECTPLACEHOLDER_CPP03

//@PURPOSE: Provide C++03 implementation for mwcu_objectplaceholder.h
//
//@CLASSES: See mwcu_objectplaceholder.h for list of classes
//
//@SEE_ALSO: mwcu_objectplaceholder
//
//@DESCRIPTION:  This component is the C++03 translation of a C++11 component,
// generated by the 'sim_cpp11_features.pl' program.  If the original header
// contains any specially delimited regions of C++11 code, then this generated
// file contains the C++03 equivalent, i.e., with variadic templates expanded
// and rvalue-references replaced by 'bslmf::MovableRef' objects.  The header
// code in this file is designed to be '#include'd into the original header
// when compiling with a C++03 compiler.  If there are no specially delimited
// regions of C++11 code, then this header contains no code and is not
// '#include'd in the original header.
//
// Generated on Wed Jun 29 04:11:12 2022
// Command line: sim_cpp11_features.pl mwcu_objectplaceholder.h

#ifdef COMPILING_MWCU_OBJECTPLACEHOLDER_H

namespace BloombergLP {
namespace mwcu {

// ===================================
// class ObjectPlaceHolder_ObjectGuard
// ===================================

template <class PLACEHOLDER>
class ObjectPlaceHolder_ObjectGuard {
    // A guard to deallocate an object in case of exception.

  private:
    // PRIVATE DATA
    PLACEHOLDER* d_placeholder_p;

  public:
    // CREATORS
    explicit ObjectPlaceHolder_ObjectGuard(PLACEHOLDER* placeholder)
        BSLS_KEYWORD_NOEXCEPT;
    // Create a 'ObjectPlaceHolder_ObjectGuard' object initialized with
    // the specified 'placeholder'.

    ~ObjectPlaceHolder_ObjectGuard();
    // Destroy this object.  Deallocate the object unless the guard was
    // released.

  public:
    // MANIPULATORS
    void release() BSLS_KEYWORD_NOEXCEPT;
    // Release this guard.
};

// =======================
// class ObjectPlaceHolder
// =======================

template <size_t SIZE>
class ObjectPlaceHolder {
    // A placeholder for any object with a local buffer of (at least) the
    // specified 'SIZE'.

  private:
    // PRIVATE TYPES
    enum State {
        // State of the placeholder.

        e_EMPTY = 0  // The placeholder is empty.
        ,
        e_FULL_INT = 1  // The placeholder contains an internal object.
        ,
        e_FULL_EXT = 2  // The placeholder contains an external object.
    };

    typedef bsls::AlignedBuffer<(
        SIZE > (sizeof(void*) * 2) ? SIZE : (sizeof(void*) * 2))>
        Buffer;
    // An aligned buffer large enough to hold two pointers - the allocator
    // pointer and the object pointer.

    typedef ObjectPlaceHolder_ObjectGuard<ObjectPlaceHolder<SIZE> >
        ObjectGuard;
    // A guard to deallocate an object in case of exception.

    // FRIENDS
    friend class ObjectPlaceHolder_ObjectGuard<ObjectPlaceHolder<SIZE> >;

  private:
    // PRIVATE CLASS DATA
    static const size_t k_BUFFER_SIZE = sizeof(Buffer);
    // The effective buffer size.

  private:
    // PRIVATE DATA
    Buffer d_buffer;
    // Unless the placeholder is empty, contains either a pair of pointers
    // - the allocator pointer and the object pointer, or the object itself.

    char d_state;
    // Placeholder state. Use 'char' instead of 'State' to reduce memory
    // footprint.

  private:
    // PRIVATE MANIPULATORS
    void storeAllocator(bslma::Allocator* allocator) BSLS_KEYWORD_NOEXCEPT;
    // Store the specified 'allocator' used to allocate the contained
    // external object into the local buffer.

    void storeObjectAddress(void* address) BSLS_KEYWORD_NOEXCEPT;
    // Save the specified 'address' of the contained external object into
    // the local buffer.

    template <class TYPE>
    TYPE* allocateObject(bslma::Allocator* allocator);
    // Return the address of a contiguous block of memory large enough to
    // accommodate an object of the specified 'TYPE'.  If the allocation
    // request exceeds the local buffer capacity, use memory obtained
    // from the specified 'allocator'.  On exception, this function has no
    // effect.  The behavior is undefined if memory was already allocated,
    // and has not already been released.

    void deallocateObject() BSLS_KEYWORD_NOEXCEPT;
    // Release memory allocated during the last successful call to
    // 'allocateObject'.  The behavior is undefined if no memory was
    // allocated, or if the memory has already been released.

  private:
    // PRIVATE ACCESSORS
    bslma::Allocator* loadAllocator() const BSLS_KEYWORD_NOEXCEPT;
    // Load the allocator used to allocate the contained object from the
    // local buffer, and return it.

    void* loadObjectAddress() const BSLS_KEYWORD_NOEXCEPT;
    // Load the address of the contained object from the local buffer, and
    // return it.

  private:
    // NOT IMPLEMENTED
    ObjectPlaceHolder(const ObjectPlaceHolder&) BSLS_KEYWORD_DELETED;
    ObjectPlaceHolder&
    operator=(const ObjectPlaceHolder&) BSLS_KEYWORD_DELETED;

  public:
    // CREATORS
    ObjectPlaceHolder() BSLS_KEYWORD_NOEXCEPT;
    // Create a 'ObjectPlaceHolder' object containing nothing.

    ~ObjectPlaceHolder();
    // Destroy this object.  The behavior is undefined unless the
    // placeholder is empty.

  public:
    // MANIPULATORS
#if BSLS_COMPILERFEATURES_SIMULATE_VARIADIC_TEMPLATES
// {{{ BEGIN GENERATED CODE
// Command line: sim_cpp11_features.pl mwcu_objectplaceholder.h
#ifndef MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT
#define MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT 9
#endif
#ifndef MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A
#define MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A                               \
    MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT
#endif
#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 0
    template <class TYPE>
    void createObject(bslma::Allocator* allocator);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 0

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 1
    template <class TYPE, class ARGS_1>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 1

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 2
    template <class TYPE, class ARGS_1, class ARGS_2>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 2

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 3
    template <class TYPE, class ARGS_1, class ARGS_2, class ARGS_3>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 3

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 4
    template <class TYPE,
              class ARGS_1,
              class ARGS_2,
              class ARGS_3,
              class ARGS_4>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 4

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 5
    template <class TYPE,
              class ARGS_1,
              class ARGS_2,
              class ARGS_3,
              class ARGS_4,
              class ARGS_5>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 5

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 6
    template <class TYPE,
              class ARGS_1,
              class ARGS_2,
              class ARGS_3,
              class ARGS_4,
              class ARGS_5,
              class ARGS_6>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 6

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 7
    template <class TYPE,
              class ARGS_1,
              class ARGS_2,
              class ARGS_3,
              class ARGS_4,
              class ARGS_5,
              class ARGS_6,
              class ARGS_7>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_7) args_7);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 7

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 8
    template <class TYPE,
              class ARGS_1,
              class ARGS_2,
              class ARGS_3,
              class ARGS_4,
              class ARGS_5,
              class ARGS_6,
              class ARGS_7,
              class ARGS_8>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_7) args_7,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_8) args_8);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 8

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 9
    template <class TYPE,
              class ARGS_1,
              class ARGS_2,
              class ARGS_3,
              class ARGS_4,
              class ARGS_5,
              class ARGS_6,
              class ARGS_7,
              class ARGS_8,
              class ARGS_9>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_7) args_7,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_8) args_8,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_9) args_9);
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_A >= 9

#else
    // The generated code below is a workaround for the absence of perfect
    // forwarding in some compilers.
    template <class TYPE, class... ARGS>
    void createObject(bslma::Allocator* allocator,
                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS)... args);
// }}} END GENERATED CODE
#endif

    template <class TYPE>
    void deleteObject() BSLS_KEYWORD_NOEXCEPT;
    // Destroy the object of the specified 'TYPE' contained in this
    // placeholder, leaving the placeholder empty.  The behavior is
    // undefined unless the placeholder contains an object of the specified
    // 'TYPE'.
    //
    // Note that 'TYPE' does not necessarily has to be the same as the
    // original type specified on object creation, as long as 'TYPE' is
    // polymorphic and is the base class of the original type.

  public:
    // ACCESSORS
    template <class TYPE>
    TYPE* object() BSLS_KEYWORD_NOEXCEPT;
    template <class TYPE>
    const TYPE* object() const BSLS_KEYWORD_NOEXCEPT;
    // Return a pointer to the contained object of the specified 'TYPE',
    // or 0 if the placeholder is empty.  The behavior is undefined unless
    // the placeholder is empty, or contains an object of the specified
    // 'TYPE'.
    //
    // Note that 'TYPE' does not necessarily has to be the same as the
    // original type specified on object creation, as long as 'TYPE' is
    // polymorphic and is the base class of the original type.

    void*       objectAddress() BSLS_KEYWORD_NOEXCEPT;
    const void* objectAddress() const BSLS_KEYWORD_NOEXCEPT;
    // Return the address of the contained object, or 0 if the placeholder
    // is empty.
};

// ============================================================================
//                           INLINE DEFINITIONS
// ============================================================================

// -----------------------------------
// class ObjectPlaceHolder_ObjectGuard
// ------------------------------------

// CREATORS
template <class PLACEHOLDER>
inline ObjectPlaceHolder_ObjectGuard<
    PLACEHOLDER>::ObjectPlaceHolder_ObjectGuard(PLACEHOLDER* placeholder)
    BSLS_KEYWORD_NOEXCEPT : d_placeholder_p(placeholder)
{
    // PRECONDITIONS
    BSLS_ASSERT_SAFE(placeholder);
}

template <class PLACEHOLDER>
inline ObjectPlaceHolder_ObjectGuard<
    PLACEHOLDER>::~ObjectPlaceHolder_ObjectGuard()
{
    if (BSLS_PERFORMANCEHINT_PREDICT_UNLIKELY(d_placeholder_p != 0)) {
        BSLS_PERFORMANCEHINT_UNLIKELY_HINT;
        d_placeholder_p->deallocateObject();
    }
}

// MANIPULATORS
template <class PLACEHOLDER>
inline void
ObjectPlaceHolder_ObjectGuard<PLACEHOLDER>::release() BSLS_KEYWORD_NOEXCEPT
{
    d_placeholder_p = 0;
}

// -----------------------
// class ObjectPlaceHolder
// -----------------------

// PRIVATE MANIPULATORS
template <size_t SIZE>
inline void ObjectPlaceHolder<SIZE>::storeAllocator(
    bslma::Allocator* allocator) BSLS_KEYWORD_NOEXCEPT
{
    // the buffer now contains a pointer to the allocator
    *reinterpret_cast<bslma::Allocator**>(d_buffer.buffer()) = allocator;
}

template <size_t SIZE>
inline void ObjectPlaceHolder<SIZE>::storeObjectAddress(void* address)
    BSLS_KEYWORD_NOEXCEPT
{
    // the buffer now contains a pointer to the object
    *reinterpret_cast<void**>(d_buffer.buffer() + sizeof(void*)) = address;
}

template <size_t SIZE>
template <class TYPE>
inline TYPE*
ObjectPlaceHolder<SIZE>::allocateObject(bslma::Allocator* allocator)
{
    // PRECONDITIONS
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    void* objectAddress;
    if (sizeof(TYPE) <= k_BUFFER_SIZE) {
        // The local buffer is large enough to satisfy the request.  Return a
        // pointer to the local buffer.

        // "allocate" memory
        objectAddress = d_buffer.buffer();

        // the placeholder now contains an internal object
        d_state = e_FULL_INT;
    }
    else {
        // The local buffer is too small to satisfy the request.  Hand over the
        // request to the allocator.

        // allocate memory
        objectAddress = allocator->allocate(sizeof(TYPE));

        // store used allocator and obtained object address
        storeAllocator(allocator);
        storeObjectAddress(objectAddress);

        // the placeholder now contains an external object
        d_state = e_FULL_EXT;
    }

    return reinterpret_cast<TYPE*>(objectAddress);
}

template <size_t SIZE>
inline void ObjectPlaceHolder<SIZE>::deallocateObject() BSLS_KEYWORD_NOEXCEPT
{
    // PRECONDITIONS
    BSLS_ASSERT_SAFE(d_state != e_EMPTY);

    if (d_state == e_FULL_INT) {
        // Released memory belongs to the local buffer.  Consider it freed.

        // NOTHING
    }
    else {
        // Released memory does not belong to the local buffer.  Hand over the
        // request to the allocator.
        loadAllocator()->deallocate(objectAddress());
    }

    // the placeholder is now empty
    d_state = e_EMPTY;
}

// PRIVATE ACCESSORS
template <size_t SIZE>
inline bslma::Allocator*
ObjectPlaceHolder<SIZE>::loadAllocator() const BSLS_KEYWORD_NOEXCEPT
{
    char* buffer = const_cast<char*>(d_buffer.buffer());
    return *reinterpret_cast<bslma::Allocator**>(buffer);
}

template <size_t SIZE>
inline void*
ObjectPlaceHolder<SIZE>::loadObjectAddress() const BSLS_KEYWORD_NOEXCEPT
{
    char* buffer = const_cast<char*>(d_buffer.buffer());
    return *reinterpret_cast<void**>(buffer + sizeof(void*));
}

// CREATORS
template <size_t SIZE>
inline ObjectPlaceHolder<SIZE>::ObjectPlaceHolder() BSLS_KEYWORD_NOEXCEPT
: d_state(e_EMPTY)
{
    // NOTHING
}

template <size_t SIZE>
inline ObjectPlaceHolder<SIZE>::~ObjectPlaceHolder()
{
    // PRECONDITIONS
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);
}

// MANIPULATORS
#if BSLS_COMPILERFEATURES_SIMULATE_VARIADIC_TEMPLATES
// {{{ BEGIN GENERATED CODE
// Command line: sim_cpp11_features.pl mwcu_objectplaceholder.h
#ifndef MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT
#define MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT 9
#endif
#ifndef MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B
#define MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B                               \
    MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT
#endif

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 0
template <size_t SIZE>
template <class TYPE>
inline void ObjectPlaceHolder<SIZE>::createObject(bslma::Allocator* allocator)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(object, allocator);

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 0

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 1
template <size_t SIZE>
template <class TYPE, class ARGS_1>
inline void
ObjectPlaceHolder<SIZE>::createObject(bslma::Allocator* allocator,
                                      BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1)
                                          args_1)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 1

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 2
template <size_t SIZE>
template <class TYPE, class ARGS_1, class ARGS_2>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 2

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 3
template <size_t SIZE>
template <class TYPE, class ARGS_1, class ARGS_2, class ARGS_3>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 3

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 4
template <size_t SIZE>
template <class TYPE, class ARGS_1, class ARGS_2, class ARGS_3, class ARGS_4>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_4, args_4));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 4

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 5
template <size_t SIZE>
template <class TYPE,
          class ARGS_1,
          class ARGS_2,
          class ARGS_3,
          class ARGS_4,
          class ARGS_5>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_4, args_4),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_5, args_5));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 5

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 6
template <size_t SIZE>
template <class TYPE,
          class ARGS_1,
          class ARGS_2,
          class ARGS_3,
          class ARGS_4,
          class ARGS_5,
          class ARGS_6>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_4, args_4),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_5, args_5),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_6, args_6));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 6

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 7
template <size_t SIZE>
template <class TYPE,
          class ARGS_1,
          class ARGS_2,
          class ARGS_3,
          class ARGS_4,
          class ARGS_5,
          class ARGS_6,
          class ARGS_7>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_7) args_7)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_4, args_4),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_5, args_5),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_6, args_6),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_7, args_7));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 7

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 8
template <size_t SIZE>
template <class TYPE,
          class ARGS_1,
          class ARGS_2,
          class ARGS_3,
          class ARGS_4,
          class ARGS_5,
          class ARGS_6,
          class ARGS_7,
          class ARGS_8>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_7) args_7,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_8) args_8)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_4, args_4),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_5, args_5),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_6, args_6),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_7, args_7),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_8, args_8));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 8

#if MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 9
template <size_t SIZE>
template <class TYPE,
          class ARGS_1,
          class ARGS_2,
          class ARGS_3,
          class ARGS_4,
          class ARGS_5,
          class ARGS_6,
          class ARGS_7,
          class ARGS_8,
          class ARGS_9>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_1) args_1,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_2) args_2,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_3) args_3,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_4) args_4,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_5) args_5,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_6) args_6,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_7) args_7,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_8) args_8,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS_9) args_9)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE*       object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS_1, args_1),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_2, args_2),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_3, args_3),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_4, args_4),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_5, args_5),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_6, args_6),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_7, args_7),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_8, args_8),
        BSLS_COMPILERFEATURES_FORWARD(ARGS_9, args_9));

    objectGuard.release();
}
#endif  // MWCU_OBJECTPLACEHOLDER_VARIADIC_LIMIT_B >= 9

#else
// The generated code below is a workaround for the absence of perfect
// forwarding in some compilers.

template <size_t SIZE>
template <class TYPE, class... ARGS>
inline void ObjectPlaceHolder<SIZE>::createObject(
    bslma::Allocator* allocator,
    BSLS_COMPILERFEATURES_FORWARD_REF(ARGS)... args)
{
    BSLS_ASSERT_SAFE(allocator);
    BSLS_ASSERT_SAFE(d_state == e_EMPTY);

    TYPE* object = allocateObject<TYPE>(allocator);
    ObjectGuard objectGuard(this);

    bslma::ConstructionUtil::construct<TYPE>(
        object,
        allocator,
        BSLS_COMPILERFEATURES_FORWARD(ARGS, args)...);

    objectGuard.release();
}

// }}} END GENERATED CODE
#endif

template <size_t SIZE>
template <class TYPE>
inline void ObjectPlaceHolder<SIZE>::deleteObject() BSLS_KEYWORD_NOEXCEPT
{
    // PRECONDITIONS
    BSLS_ASSERT_SAFE(d_state != e_EMPTY);

    // destroy object
    bslma::DestructionUtil::destroy(object<TYPE>());

    // release memory
    deallocateObject();
}

// ACCESSORS
template <size_t SIZE>
template <class TYPE>
inline TYPE* ObjectPlaceHolder<SIZE>::object() BSLS_KEYWORD_NOEXCEPT
{
    return reinterpret_cast<TYPE*>(objectAddress());
}

template <size_t SIZE>
template <class TYPE>
inline const TYPE*
ObjectPlaceHolder<SIZE>::object() const BSLS_KEYWORD_NOEXCEPT
{
    return reinterpret_cast<const TYPE*>(objectAddress());
}

template <size_t SIZE>
inline void* ObjectPlaceHolder<SIZE>::objectAddress() BSLS_KEYWORD_NOEXCEPT
{
    if (d_state == e_EMPTY) {
        return 0;  // RETURN
    }

    // The object is either located internally or externally.  In the first
    // case, return the address of the local buffer, in the second case,
    // extract the address of the object from the local buffer.

    char* buffer = const_cast<char*>(d_buffer.buffer());

    return d_state == e_FULL_INT ? static_cast<void*>(buffer)
                                 : loadObjectAddress();
}

template <size_t SIZE>
inline const void*
ObjectPlaceHolder<SIZE>::objectAddress() const BSLS_KEYWORD_NOEXCEPT
{
    return const_cast<ObjectPlaceHolder*>(this)->objectAddress();
}

}  // close package namespace
}  // close enterprise namespace

#else  // if ! defined(DEFINED_MWCU_OBJECTPLACEHOLDER_H)
#error Not valid except when included from mwcu_objectplaceholder.h
#endif  // ! defined(COMPILING_MWCU_OBJECTPLACEHOLDER_H)

#endif  // ! defined(INCLUDED_MWCU_OBJECTPLACEHOLDER_CPP03)

// ----------------------------------------------------------------------------
// Copyright 2022-2023 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
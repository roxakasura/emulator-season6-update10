#ifndef ARIES_PROTECTOR_INCLUDE_LINKED_LIST_H
#define ARIES_PROTECTOR_INCLUDE_LINKED_LIST_H
// -----------------------------------------------------------------------------

#include "macro.h"
// -----------------------------------------------------------------------------

template <typename T>
class LinkNode {
  public:
    LinkNode() : previous_ ( nullptr ), next_ ( nullptr ) {}
    LinkNode ( LinkNode<T>* previous, LinkNode<T>* next ) :
        previous_ ( previous ), next_ ( next ) {}
    virtual ~LinkNode() { RemoveFromList(); }

    // Insert |this| into the linked list, before |e|.
    void InsertBefore ( LinkNode<T>* e ) {
        this->next_ = e;
        this->previous_ = e->previous_;
        // do linkedlisk có cấu trúc danh sách liên kết vòng
        // nên trường hợp e->previous_ = nullptr là ko xảy ra
        e->previous_->next_ = this;
        e->previous_ = this;
    }

    // Insert |this| into the linked list, after |e|.
    void InsertAfter ( LinkNode<T>* e ) {
        this->next_ = e->next_;
        this->previous_ = e;
        // do linkedlisk có cấu trúc danh sách liên kết vòng
        // nên trường hợp e->next_ = nullptr là ko xảy ra
        e->next_->previous_ = this;
        e->next_ = this;
    }

    // Remove |this| from the linked list.
    void RemoveFromList() {
        if ( this->previous_ ) {
            this->previous_->next_ = this->next_;
        }

        if ( this->next_ ) {
            this->next_->previous_ = this->previous_;
        }

        // next() and previous() return non-NULL if and only this node is not in any
        // list.
        this->next_ = nullptr;
        this->previous_ = nullptr;
    }

    // DANGEROUS: make sure you create this with new operator before call this
    void Free() {
        RemoveFromList();
        T * v = value();
        delete ( v );
    }

    LinkNode<T>* previous() const {
        return previous_;
    }

    LinkNode<T>* next() const {
        return next_;
    }

    // Cast from the node-type to the value type.
    const T* value() const {
        return static_cast<const T*> ( this );
    }

    T* value() {
        return static_cast<T*> ( this );
    }

  protected:
    // not use

  private:
    LinkNode<T> * previous_;
    LinkNode<T> * next_;

  private:
    DISALLOW_COPY_AND_ASSIGN ( LinkNode );
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

template <typename T>
class LinkedList {
  public:
    // The "root" node is self-referential, and forms the basis of a circular
    // list (root_.next() will point back to the start of the list,
    // and root_->previous() wraps around to the end of the list).
    LinkedList() : root_ ( &root_, &root_ ) {}

    // Appends |e| to the end of the linked list.
    void Append ( LinkNode<T>* e ) {
        e->InsertBefore ( &root_ );
    }

    LinkNode<T>* head() const {
        return root_.next();
    }

    LinkNode<T>* tail() const {
        return root_.previous();
    }

    const LinkNode<T>* end() const {
        return &root_;
    }

    bool empty() const {
        return head() == end();
    }

    void FreeAll() {
        while ( !empty() ) {
            head()->Free();
        }
    }

  protected:
    // not use
  private:
    LinkNode<T> root_;

  private:
    DISALLOW_COPY_AND_ASSIGN ( LinkedList );
};
// -----------------------------------------------------------------------------
#endif  // ARIES_PROTECTOR_INCLUDE_LINKED_LIST_H
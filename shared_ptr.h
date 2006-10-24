//---------------------------------------------------------------------------

#ifndef shared_ptrH
#define shared_ptrH
//---------------------------------------------------------------------------
namespace DoxEngine
{
  template <class T> class shared_ptr
  {
    public:
      // Constructors
      shared_ptr()
{
  ptr = NULL;
  count = new int;
  *count = 1;
}


      shared_ptr(const shared_ptr<T> &original)
{
  ptr = original.ptr;
  count = original.count;
  (*count)++;
}

      shared_ptr(T* original)
{
  ptr = original;
  count = new int;
  *count = 1;
}

      ~shared_ptr()
{
  Release();
}


      //assignment
      shared_ptr<T> &operator=(const shared_ptr &rhs)
{
  if (this == &rhs)
    return *this;

  Release();
  ptr = original.ptr;
  count = original.count;
  Acquire();

  return *this;
}

      shared_ptr<T> &operator=(const T* rhs)
{
  if (ptr == rhs)
    return this;

  Release();
  ptr = original;
  count = new int;
  *count = 1;
}


      //Use
      T* operator->()
{
  return ptr;
}


    private:
      T* ptr;
      int* count;

      Acquire()
      {
        (*count)++;
      }
      
      Release()
{
  (*count)--;
  if (!(*count))
  {
    delete count;

    if (ptr)
      delete ptr;

    ptr = NULL;
  }

}
  // Comparison
  bool operator>(const shared_ptr<T> &rhs)
  {
    return this>&rhs;
  }

  };
}
#endif

#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> 
{

    private:
    
		Node<T>* first;
		int n;
    public:
		ListLinked()
		{
			n = 0;
			first = nullptr;
		}
		
		~ListArray()
		{
			while(first != nullptr)
			{
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
		}

		void insert(int pos, T e) override
		{
			if(pos < 0 || pos > n)
				throw std::out_of_range("La posicion no es valida para el vector");
			if(size() == max)
				resize(size()*2);
				
			if(pos == 0)
				prepend(e);
			else
			{
				if(pos == n)
					append(e);
				else
				{
					for(int i=n; i>pos; i--)
						arr[i] = arr[i-1]; 
					arr[pos] = e;
					n++;
				}
			}
			
		}
		
		virtual void append(T e) override
		{ 
			
			if(size() == max)
             			resize(size()*2);
			arr[n] = e;
			n++;
		}

		virtual void prepend(T e) override
		{ 
		
			if(size() == max)
	     			resize(size()*2);
      			else
      			{
	      			for(int i = n; i > 0; i --)
		      			arr[i] = arr[i-1];	
				arr[0] = e;
	      			n++;
      			} 
		}

		virtual T remove(int pos) override
		{
			if(pos < 0 || pos > size()-1)
				throw std::out_of_range("La posicion no es valida para el vector");
			T aux = arr[pos];

			for(int i=pos; i<n; i++)
				arr[i] = arr[i+1];
			n--;

			return aux;
		}

		virtual T get(int pos) override
		{
			if(pos < 0 || pos > size()-1)
				throw std::out_of_range("La posicion no es valida para el vector");
			return arr[pos];
		}

		virtual int search(T e) override
		{
			for(int i=0; i<n; i++)
				if(arr[i] == e)
					return i;
			return -1;
		}

		virtual bool empty() override
		{
			if(n == 0)
				return true;
			else
				return false;	
		}

		virtual int size() override
		{
			return n;
		}
		
		T operator[](int pos)
		{
			if(pos < 0 || pos > n)
			       	throw std::out_of_range("La posicion no es valida para el vector");
			Node<T>* aux = first;
			for(int i=1; i<pos; i++)
				aux = aux->next;
			return aux->data;
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
		{
			out << "List -> [";
			for(int i=0; i<list.n; i++)
				out << list.arr[i] <<" ";
			out << "]";
			return out;
		}
		
};

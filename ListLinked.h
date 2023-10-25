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
		
		~ListLinked()
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
				throw std::out_of_range("La posicion no es valida para el nodo");
				
			if(pos == 0)
				prepend(e);
			else
			{
				if(pos == n)
					append(e);
				else
				{
					Node<T>* aux = first;
					for(int i=1; i<pos; i++)
						aux = aux->next;
					Node<T>* aux2 = new Node<T>(e, aux->next);
					aux->next = aux2;
					n++;
				}
			}
			
		}
		
		virtual void append(T e) override
		{ 
			
			if(first == nullptr)
             			prepend(e);
			else
			{
				Node<T>* aux = first;
				for(int i=1; i<size(); i++)
					aux = aux->next;
				Node<T>* aux2 = new Node<T>(e, aux->next);
				aux->next = aux2;
				n++;
			}
		}

		virtual void prepend(T e) override
		{
			Node<T>* aux = new Node<T>(e,first);
			first = aux;
			n++;
		}

		virtual T remove(int pos) override
		{
			Node<T>* aux = first;
    			Node<T>* bas;
    			int borr;
    			if(pos > size()-1|| pos < 0)
      				throw std::out_of_range("La posicion no es valida para el nodo");
    
    			else
			{
      				if(pos == 0)
				{
					first= aux->next;
 					bas = aux;	 
					borr = bas->data;

      				}
      				else
      				{
					for(int i = 1; i < pos;i++)
	 					aux = aux->next;
		
					bas = aux->next;
					borr = bas->data;
					aux->next = bas->next;
     				}
      				n--;
      				delete bas;
      				return borr;
    			}
		}

		virtual T get(int pos) override
		{
			if(pos < 0 || pos > size()-1)
				throw std::out_of_range("La posicion no es valida para el vector");
			else
			{
				Node<T>* aux = first;
				for(int i=0; i<pos; i++)
					aux = aux->next;
				return aux->data;
			}
		}

		virtual int search(T e) override
		{
			Node<T>* aux = first;
			for(int i=0; i<n; i++)
			{
				if(aux->data == 0)
					return i;
				aux = aux->next;
			}
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
		
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
		{
			out << "List -> [";
			Node<T>* aux = list.first;

			while(aux)
			{	
				out << aux->data <<" ";
				aux = aux->next;
			}
			out << "]";
			
			return out;
		}
		
};

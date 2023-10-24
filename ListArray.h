#include <ostream>
#include "List.h"
#include <vector>

template <typename T>
class ListArray : public List<T> 
{
	private:
		T* arr;
		int max;
		int n;
		static const int MINISIZE = 2;

		void resize(int new_size)
		{
			T arr_aux[new_size];
			for(int i = 0; i<n ; i++)
				arr_aux[i] = arr[i];

			delete[] arr;

			arr = new int[new_size];
			for(int j = 0; j<new_size; j++)
				arr[j] = arr_aux[j];

			max = new_size;
		}

	public:
		ListArray()
		{
			arr = new int[MINISIZE];
			max = MINISIZE;
			n = 0;
		}
		
		~ListArray()
		{
			delete[] arr;
		}

		T operator[](int pos)
		{
			if(pos < 0 || pos > size()-1)
			       	throw std::out_of_range("La posicion no es valida para el vector");
			else
				return arr[pos];	
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
		{
			out << "List -> [";
			for(int i=0; i<list.n; i++)
				out << list.arr[i] << ", ";
			out << "j";
			return out;
		}

		virtual void insert(int pos, T e) override
		{
			if(pos < 0 || pos > size()-1)
				throw std::out_of_range("La posicion no es valida para el vector");
			else 
			{
				if(pos == 0)
					prepend(e);
				else
				{
					if(pos == n)
						append(e);
					else
					{
						resize(size()+1);
						for(int i=size()-1; i>=pos; i++)
							arr[i+1] = arr[i]; 
						arr[pos-1] = e;
					}
				}
			}
		}

		virtual void append(T e) override
		{
			resize(size()+1);
			arr[size()-1]=e;
		}

		virtual void prepend(T e) override
		{
			resize(size()+1);
			for(int i=size()-1;i>0;i--)
				arr[i+1] = arr[i];
			arr[0] = e;
		}

		virtual T remove(int pos) override
		{
			if(pos < 0 || pos > size()-1)
				throw std::out_of_range("La posicion no es valida para el vector");
			else
			{
				T aux = arr[pos-1];
	
				for(int i=pos-1; i<size(); i++)
					arr[i] = arr[i+1];
				resize(size()-1);
	
				return aux;
			}
		}

		virtual T get(int pos) override
		{
			if(pos < 0 || pos > size()-1)
				throw std::out_of_range("La posicion no es valida para el vector");
			else
				return arr[pos];
		}

		virtual int search(T e) override
		{
			int j=-1;
			for(int i=0; i<n; i++)
				if(arr[i] == e)
					j=i;
			return j;
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

};

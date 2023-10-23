#include <ostream>
#include "List.h"
#include <vector>

usingnamespace std;

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

		T oeprator[](int pos)
		{
			if(pos < 0 || pos > max-1)
			       	throw out_of_range("La posicion no es valida para el vector");
			else
				return arr[pos];	
		}
		
		friend ostream& operator<<(ostream &out, const ListArray<T> &list)
		{
			out << "List -> [";
			for(int i=0; i<list.n; i++)
				out << list.arr[i] << ", ";
			out << "j";
			return out;
		}


};

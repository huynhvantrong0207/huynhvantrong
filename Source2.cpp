#include <stdio.h>
#include <iostream>
using namespace std;

typedef class node* Node;
class node{
	private :
		int gtri;
		Node tiep;
	public :
		node(int gtri)
		{
			this->gtri = gtri;
			this->tiep = NULL;
		}
		void Xuat()
		{
			printf("%d ",this->gtri);
		}
		void setNext(Node tiep)
		{
			this->tiep = tiep;
		}
		Node getNext()
		{
			return this->tiep;
		}
		int getGtri()
		{
			return this->gtri;
		}
		void setGtri(int gtri)
		{
			this->gtri = gtri;
		}
};

typedef class ds* Ds;
class ds{
	private:
		Node dau;
	public:
		ds()
		{
			dau = NULL;
		}
		void ThemDau(Node tam)
		{
			if(this->dau==NULL)
				this->dau = tam;
			else
			{
				tam->setNext(dau);
				dau = tam;
			}
		}
		void ThemNut(Node tam)
		{
			if(this->dau==NULL)
			{
				this->ThemDau(tam);
			}
			else
			{
				Node p = this->dau;
				while(p->getNext()!=NULL)
				{
					p = p->getNext();
				}
				p->setNext(tam);	
			}
		}
		void XuatDs()
		{
			Node p = this->dau;
			while(p!=NULL)
			{
				printf("%d ",p->getGtri());
				p = p->getNext();
			}
		}
		
/*============================================BubleSort=====================================================*/
		void bublesort()
		{
			if(this->dau!=NULL)
			{
				Node p = this->dau;
				Node q;
				while(p->getNext()!=NULL)
				{
					q = p->getNext();
					while(q!=NULL)
					{
						if(p->getGtri() > q->getGtri())
						{
							int tam = q->getGtri();
							q->setGtri(p->getGtri());
							p->setGtri(tam);
						}
						q = q->getNext();
					}
					p = p->getNext();
				}
			}			
		}
		
/*============================================SelectionSort=====================================================*/
		void selection() 
		{
			
			Node p, q;
			Node t = NULL;
			p = dau;
			while (p->getNext() != NULL)
			{
				q = p->getNext();
				while (q != NULL)
				{
					if (q->getGtri() < p->getGtri())
					{
						int tam = q->getGtri();
						q->setGtri(p->getGtri());
						p->setGtri(tam);
					}
					q = q->getNext();
				}
	
				p = p->getNext();
			}
		}
		
/*============================================InsertSort=====================================================*/
		void insertionSort()
		{
			int length = 0, i = 0;
			Node p = NULL;
			//luot qua danh sach node de tinh do dai cua danh sach
			p = dau;
			while (p != NULL)
			{
				p = (p->getNext());
				length++;
			}
	
			//tao 1 mang dong voi do dai vua lay duoc
			int *arr = new int[length];
	
			//gan gia tri cua tung node vao mang vua tao
			p = dau;
			i = 0;
			while (p != NULL)
			{
				*(arr + i) = p->getGtri();
				p = p->getNext();
				i++;
			}
	
			//su dung con tro
			int key, j;
			i = 1;
			for (i = 1; i < length; i++)
			{
				key = *(arr + i);
				j = i - 1;
	
				/* Di chuyen cac phan tu có giá tri lon hon giá tri
				khoa ve sau mot vi trí so voi vi trí ban dau
				cua nó */
				while (j >= 0 && *(arr + j) > key)
				{
					//arr[j + 1] = arr[j];
					*(arr + j + 1) = *(arr + j);
					j = j - 1;
				}
				//arr[j + 1] = key;
				*(arr + j + 1) = key;
			}

			//cap nhat gia tri sau khi sap xep vao danh sach node
			p = dau;
			i = 0;
			while (p != NULL)
			{
				p->setGtri(*(arr + i));
				p = (p->getNext());
				i++;
			}
			//xoa con tro cap phat dong
			delete[]arr;
	}
/*============================================HeaptSort=====================================================*/
	void heapify(int *arr, int n, int i)
	{
		int largest = i; // khoi tao gri goc lon nhat = i
		int l = 2 * i + 1; // left = 2*i + 1 
		int r = 2 * i + 2; // right = 2*i + 2 

		// neu left > goc
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// neu right > goc
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// neu lon nhat khong phai la goc 
		if (largest != i)
		{
			swap(arr [i], arr[largest]);
			heapify(arr, n, largest);
		}
	}
	
	void heapSort()
	{

		int n = 0;
		Node p = NULL;
		//tinh do dai cua danh sach
		p = dau;
		while (p != NULL)
		{
			p = (p->getNext());
			n++;
		}

		//tao 1 mang voi do dai vua tinh duoc
		int* arr = new int[n];

		//lay gia tri trong danh sach node gan vao mang
		p = dau;
		int j = 0;
		while (p != NULL)
		{
			*(arr + j) = p->getGtri();
			p = p->getNext();
			j++;
		}

		//sap xep mang
		
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		// trich xuat tung phan tu 
		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
		//cap nhat gia tri danh sach node
		p = dau;
		int i = 0;
		while (p != NULL)
		{
			p->setGtri(arr[i]);
			p = (p->getNext());
			i++;
		}
		delete[]arr;
	}
/*============================================QuickSortSort=====================================================*/
	//khoi tao vach ngan
	int partition(int arr[], int low, int high)
	{
		int pivot = arr[high];    // pivot
		int left = low;
		int right = high - 1;
		while (true) {
			while (left <= right && arr[left] < pivot) left++;
			while (right >= left && arr[right] > pivot) right--;
			if (left >= right) break;
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
		swap(arr[left], arr[high]);
		return left;
	}

	void quickSort(int arr[], int low, int high)
	{
		if (low < high)
		{
			/* pi: chia mang làm 2 mang con trái & phai */
			int pi = partition(arr, low, high);

			//  sap xep 2 mang con trái và phai
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	
	void quickSort()
	{
		int n = 0;
		Node p = NULL;

		//tinh do dai danh sach node
		p = dau;
		while (p != NULL)
		{
			p = (p->getNext());
			n++;
		}

		//tao 1 mang voi do dai vua tinh duoc
		int* arr = new int[n];

		//gan gia tri trong danh sach node vao mang
		p = dau;
		int j = 0;
		while (p != NULL)
		{
			*(arr + j) = p->getGtri();
			p = p->getNext();
			j++;
		}

		//sap xep
		quickSort(arr, 0, n - 1);

		//cap nhat gia tri vao danh sach node
		p = dau;
		int i = 0;
		while (p != NULL)
		{
			p->setGtri(arr[i]);
			p = (p->getNext());
			i++;
		}
		delete[]arr;
	}
/*============================================Timkiem=====================================================*/
	int TimKiem(int gtri)
		{
			if(this->dau!=NULL)
			{
				Node p = this->dau;
				int dem = 1;
				while(p!=NULL)
				{
					if(p->getGtri()==gtri)
						return dem;
					else
					{
						p = p->getNext();
						dem++;
					}
				}
			}		
			return -1;
		}
};

/*============================================DocFile=====================================================*/
void DocFile(Ds &nodes, int &n, int &k)
{
	FILE *fp = fopen("data.txt","r");
	int tam;
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&k);
	for(int i=0;i<n;i++)
	{
		fscanf(fp,"%d",&tam);
		nodes->ThemNut(new node(tam));
	}
}

int main()
{
	int n,k,vtri;
	Ds nodes = new ds();
	printf("Danh sach sau khi doc file\n");
	DocFile(nodes,n,k);
	nodes->XuatDs();
	printf("\n\nDanh sach sau khi sap xep BubleSort\n");
	nodes->bublesort();
	nodes->XuatDs();
	printf("\n\nDanh sach sau khi sap xep SelectionSort\n");
	nodes->selection();
	nodes->XuatDs();
	printf("\n\nDanh sach sau khi sap xep InsertionSort\n");
	nodes->insertionSort();
	nodes->XuatDs();
	printf("\n\nDanh sach sau khi sap xep HeapSort\n");
	nodes->heapSort();
	nodes->XuatDs();
	printf("\n\nDanh sach sau khi sap xep QuickSort\n");
	nodes->quickSort();
	nodes->XuatDs();
	vtri = nodes->TimKiem(k);
	printf("\n\nVi tri cua %d trong danh sach la : %d",k,vtri);
	return 1;
}

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;							// ������� ���, ��� �� ������ ��'����� � ������ ���������� ����
												// ������������



double MinElement(double*& b, int n);					//���� �������� �������� t(�������� � �����) 
int MinIndex(double*& b, int n, double mint);	//���� ������ �������� t
void Print(double*& b, int n);					//�������� �� ����� �����
void createArr(double*& b, int n);				//��������� ������� ����� � ������� (-10;10)
double negativeLeftElement(double*& b, int n, int N);		//���� ����� ��'���� t ����
double SumBetweenElements(double*& b, int firstElementIndex, int secondElementIndex, double sum);	//����� ���� �� ����� ���������� � �����, �� ��������� ��
void changeArr(double*& b, int n);
int main() {
	int n, firstNegativeElementIndex, secondNegativeElementIndex;
	double minIndex, minElement, firstNegativeElement, secondNegativeElement, sumBetweenElements, sum = 0;
	cout << "1.1---------------------------------------------" << endl;
	cout << "n -> ? ";cin >> n;
	double* b = new double[n];
	srand((unsigned)time(NULL));

	createArr(b, n);

	Print(b, n);

	minElement = MinElement(b, n);				//����� ���������� �������� � �����
	minIndex = MinIndex(b, n, minElement);	//����� ���� �� ����������� ��������� �������
	cout << endl
		<< "min element:" << endl << minElement << endl
		<< "min element number: " << endl << minIndex << endl << endl;
	cout << "1.2---------------------------------------------" << endl;

	firstNegativeElement = negativeLeftElement(b, n, 0);
	firstNegativeElementIndex = MinIndex(b, n, firstNegativeElement);
	cout << "first negative element " << firstNegativeElement << endl;
	cout << "first negative element index " << firstNegativeElementIndex << endl << endl;

	secondNegativeElement = negativeLeftElement(b, n, firstNegativeElementIndex + 1);
	secondNegativeElementIndex = MinIndex(b, n, secondNegativeElement);
	cout << "second negative element " << secondNegativeElement << endl;
	cout << "second negative element index " << secondNegativeElementIndex << endl << endl;

	sumBetweenElements = SumBetweenElements(b, firstNegativeElementIndex, secondNegativeElementIndex, sum);
	cout << "sum between first and second negative elements " << sumBetweenElements << endl;

	cout << "2-----------------------------------------------" << endl;
	changeArr(b, n);
	Print(b, n);
	return 0;
}
void changeArr(double*& b, int n) {
	double x, y, z;
	int k = 0, l = 0, j = 0, i = 0, r = 0;
	
		for (int g = 0; g < n; g++) {		//�������� �� ������ �������� ����
			if (abs(b[g]) < 1) {
				x = b[g];
				k = g;
				for (k; k > 0; k--) {
					b[k] = b[k - 1];
				}
				b[0] = x;
				k = g + 1;
				r = 1;
				break;
			}
		}
		if (r == 1) {						
			r = 0;
			for (k; k < n; k++) {			//�������� �� ������ ���� �� �
				if (abs(b[k]) < 1) {
					y = b[k];
					l = k;
					for (l; l > 1; l--)
						b[l] = b[l - 1];
					b[1] = y;
					l = k + 1;
					r = 1;
					
				}
				if (r == 1) {
					for (l; l < n; l++) {	//�������� �� ����� ���� �� �
						if (abs(b[l]) < 1) {
							z = b[l];
							j = l;
							for (j; j > 2; j--)
								b[j] = b[j - 1];
							b[2] = z;
							break;
						}
					}
				}
			}
		}
		else 
			cout << "there aren't numbers that < 1" << endl;
		
	}
double SumBetweenElements(double*& b, int firstElementIndex, int secondElementIndex, double sum) {
	if (b[firstElementIndex + 1] == b[secondElementIndex]) 
			sum = 0;
	else
		for (firstElementIndex, secondElementIndex; firstElementIndex + 1 < secondElementIndex; firstElementIndex++)
			sum += b[firstElementIndex + 1];
	return sum;
}

double negativeLeftElement(double*& b, int n, int N) { //N �� ��������� n;
	int i;
	for ( i = N; i < n; i++) {
		if (b[i] >= 0)
			;
		else if (b[i] < 0)
			break;
	}
	return b[i];
}

double MinElement(double*& b, int n) {
	double t = b[0];
	for (int i = 0; i < n; i++) {
		if (t > b[i + 1])
			t = b[i + 1];

		else if (t < b[i + 1]) {
			t = t;
		}
	}
	return t;
}
int MinIndex(double*& b, int n,double mint) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (mint == b[i])
			break;
		index++;
	}
	return index;
}

void Print(double*& b, int n) {
	cout << "array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(3) << setprecision(4) << " " << b[i];
	}
}
void createArr(double*& b, int n) {
	double x;
	for (int i = 0; i < n; i++) {
		double r = -5 + (double)rand() * 10 / RAND_MAX;	//������� ���������� ����� �� -5 �� 5
		b[i] = r;
	}	
	
}

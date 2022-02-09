#include<iostream>
#include<memory>
//template<typename T, // template for n x n matrices of
//	std::size_t n> // objects of type T; see below for info
//	class SquareMatrix { // on the size_t parameter
//	public:
//		template<class D>
//		SquareMatrix(D n) :n_(n) {  }
//		void invert(); // invert the matrix in place
//	private:
//		int n_;
//};
//
//template<typename T,std::size_t n>
//void SquareMatrix<T,n>::invert() {
//	std::cout << "Call SquareMatrix<T,n>::invert " << n_ <<" * " << n_ <<" sizes.\n";
//}

/* An alternative is to have SquareMatrixBase store a pointer to the
	memory for the matrix values.*/

template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T* pMem) // store matrix size and a
		: size_(n), data_(pMem) {} // ptr to matrix values
	void SetDataPtr(T* ptr) { data_ = ptr; } // reassign pData
private:
	std::size_t size_; // size of matrix
	T* data_; // pointer to matrix values
};

template<typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> {
public:
	SquareMatrix() :SquareMatrixBase<T>(n, 0), data_ptr_(new T[n * n]) {
		this->SetDataPtr(data_ptr_.get());
	}
	void invert(); // invert the matrix in place

private:
	std::unique_ptr<T[]> data_ptr_;
	// https://stackoverflow.com/questions/8624146/does-c11-have-wrappers-for-dynamically-allocated-arrays-like-boosts-scoped-ar
};

template<typename T,std::size_t n>
void SquareMatrix<T,n>::invert() {
	std::cout << "Call SquareMatrix<T,n>::invert " << n <<" * " << n <<" sizes.\n";
}

int main() {
	std::cout << "Item 44: Factor parameter-independent code out of templates.\n";
	//{
	//	SquareMatrix<double, 5> sm1(5);
	//	sm1.invert();

	//	SquareMatrix<double, 10> sm2(10);
	//	sm2.invert(); // call SquareMatrix<double, 10>::invert
	//}
	{
		SquareMatrix<double, 5> sm3;
		sm3.invert();
	}
	return 0;
}
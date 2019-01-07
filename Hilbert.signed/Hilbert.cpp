/***** Complete this program. *****/
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
using std::showpoint;


const int MAX_SIZE = 5;  // maximum matrix size

// Error codes for singular matrices, which cannot be inverted.
enum ErrorCode {ZERO_ROW, SINGULAR_MATRIX, NO_CONVERGENCE};

/**
 * Invert a matrix using the LU Decomposition Algorithm.
 * @param n the size of the matrix.
 * @param A the matrix to invert.
 * @param Ainv the computed inverse of A.
 */
void invert(const int n, double A[][MAX_SIZE], double Ainv[][MAX_SIZE]);

/**
 * Decompose matrix A by computing lower and upper triangular matrices
 * L and U and permutation matrix P so that LU = PA. Store L-I and U in LU.
 * A and LU can be passed the same matrix.
 * @param n the size of the matrices.
 * @param A the matrix to decompose.
 * @param LU the computed decomposition such that LU = PA.
 * @param ps the computed permuted row indices.
 */
void decompose(const int n, double A[][MAX_SIZE],
               double LU[][MAX_SIZE], int ps[MAX_SIZE]);

/**
 * Solve Ax = b using LU from function decompose.
 * @param n the size of the matrices and vectors.
 * @param A the coefficient matrix.
 * @param x the computed solution vector.
 * @param b the right-hand-side vector.
 * @param ps the permuted row indices.
 */
void solve(const int n, double LU[][MAX_SIZE],
           const double b[], double x[], const int ps[MAX_SIZE]);

/**
 * Indicate a singular matrix.
 * @param code the error code.
 */
void singular(const ErrorCode code);

/**
 * The main.
 * Repeatedly prompt the user for the size of the Hilbert matrix
 * and then perform the computations.
 */

//Function to compute product of two matrix
void mult( int size_matrix,double hil_mat[][MAX_SIZE],double inv_hil_mat[][MAX_SIZE]) {
	double result[MAX_SIZE][MAX_SIZE];
	for(int i=0; i<size_matrix; i++) {
		for(int j=0; j<size_matrix; j++) {
			for(int k=0; k<size_matrix; k++) {
				result[i][j]+=hil_mat[i][k]*inv_hil_mat[k][j];
			}
		}
	}

	cout<<endl;
	cout<<endl;
	cout<<"Hilbert matrix multiplied by its inverse:"<<endl;
	for(int i=0; i<size_matrix; i++) {
		cout<<endl;
		for(int j=0; j<size_matrix; j++) {
			if(result[i][j]>=1) {
				cout<<fixed;
				cout<<setprecision(6);
				cout<<result[i][j]<<"      ";
			}
			if(result[i][j]<1 && result[i][j]!=0.5) {
				cout<<fixed;
				cout<<setprecision(6);
				cout<<result[i][j]<<"  ";
			}

			if(result[i][j]==0.5) {
				cout<<fixed;
				cout<<setprecision(6);
				cout<<result[i][j]<<"    ";
			}

		}
	}
}
int main() {
	int size_matrix=0;
	//Asking for User Input until Invalid Input is entered
	do {
		cout<<"Size of Hilbert matrix (1-5)?"<<endl;
		cin>>size_matrix;
		//Checks if valid input is entered
		if(size_matrix!=0) {

			// Calculating Hilbert Matrix
			double hil_mat[MAX_SIZE][MAX_SIZE];
			for(int i=1; i<=size_matrix; i++) {
				for(int j=1; j<=size_matrix; j++) {
					hil_mat[i-1][j-1]=1.0/(i+j-1);
				}
			}
			//Printing Hilbert Matrix
			cout<<"Hilbert matrix of size "<<size_matrix<<":"<<endl;
			for(int i=0; i<size_matrix; i++) {
				cout<<endl;
				for(int j=0; j<size_matrix; j++) {
					if(hil_mat[i][j]>=1) {
						cout<<fixed;
						cout<<setprecision(6);
						cout<<hil_mat[i][j]<<"      ";
					}
					if(hil_mat[i][j]<1 && hil_mat[i][j]!=0.5) {
						cout<<fixed;
						cout<<setprecision(6);
						cout<<hil_mat[i][j]<<"  ";
					}

					if(hil_mat[i][j]==0.5) {
						cout<<fixed;
						cout<<setprecision(6);
						cout<<hil_mat[i][j]<<"    ";
					}

				}
			}

			cout<<endl;
			cout<<endl;

			//Computing Inverse of Hilbert Matrix
			double inv_hil_mat[MAX_SIZE][MAX_SIZE];
			invert(size_matrix,hil_mat,inv_hil_mat);
			//Printing Inverted Hilbert Matrix
			cout<<"Hilbert matrix inverted:"<<endl;
			for(int i=0; i<size_matrix; i++) {
				cout<<endl;
				for(int j=0; j<size_matrix; j++) {
					if(inv_hil_mat[i][j]>=1) {
						cout<<showpoint;
						cout<<inv_hil_mat[i][j]<<"      ";
					}
					if(inv_hil_mat[i][j]<1 && inv_hil_mat[i][j]!=0.5) {
						cout<<showpoint;
						cout<<inv_hil_mat[i][j]<<"  ";
					}

					if(inv_hil_mat[i][j]==0.5) {
						cout<<showpoint;
						cout<<inv_hil_mat[i][j]<<"    ";
					}

				}
			}
			//Multiplying Hilbert Matrix by its Inverse by calling Function


			mult(size_matrix,hil_mat,inv_hil_mat);

			//Computing Inverse of Invereted Hilbert Matrix
			double inv_result [MAX_SIZE][MAX_SIZE];
			invert(size_matrix,inv_hil_mat,inv_result);
			cout<<endl;
			cout<<endl;
			cout<<"Inverse Hilbert matrix inverted:"<<endl;
			// cout<<endl;
			for(int i=0; i<size_matrix; i++) {
				cout<<endl;
				for(int j=0; j<size_matrix; j++) {
					if(inv_result[i][j]>=1) {
						cout<<fixed;
						cout<<setprecision(6);
						cout<<inv_result[i][j]<<"      ";
					}
					if(inv_result[i][j]<1 && inv_result[i][j]!=0.5) {
						cout<<fixed;
						cout<<setprecision(6);
						cout<<inv_result[i][j]<<"  ";
					}

					if(inv_result[i][j]==0.5) {
						cout<<fixed;
						cout<<setprecision(6);
						cout<<inv_result[i][j]<<"    ";
					}

				}
			}



			cout<<endl;
			cout<<endl;
		}

		else
			break;

	} while(size_matrix>=1 && size_matrix<=5);

	cout<<"Done!" << endl;
	return 0;
}


void invert(const int n, double A[][MAX_SIZE], double Ainv[][MAX_SIZE]) {
	double LU[MAX_SIZE][MAX_SIZE];
	double x[MAX_SIZE];  // solution vector
	double b[MAX_SIZE];  // right-hand-side vector
	int ps[MAX_SIZE];    // permuted row indices

	decompose(n, A, LU, ps);

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			b[i] = i == j ? 1 : 0;
		}

		solve(n, LU, b, x, ps);
		for (int i = 0; i < n; i++) Ainv[i][j] = x[i];
	}
}

void decompose(const int n, double A[][MAX_SIZE],
               double LU[][MAX_SIZE], int ps[MAX_SIZE]) {
	double scales[MAX_SIZE];  // vector of scaling factors
	int pivot_index;
	double norm_row, pivot, size, biggest, mult;

	// Initialize ps, LU, and scales.
	for (int i = 0; i < n; i++) {
		ps[i] = i;
		norm_row = 0;

		for (int j = 0; j < n; j++) {
			LU[i][j] = A[i][j];

			// Find the largest row element.
			if (norm_row < abs(LU[i][j])) norm_row = abs(LU[i][j]);
		}

		// Set the scaling factor for row equilibration.
		if (norm_row != 0) scales[i] = 1/norm_row;
		else {
			scales[i] = 0;
			singular(ZERO_ROW);
		}
	}

	// Gaussian elimination with partial pivoting.
	for (int k = 0; k < n-1; k++) {
		pivot_index = -1;
		biggest = 0;

		// Go down rows from row k.
		for (int i = k; i < n; i++) {
			// Divide by the largest row element.
			size = abs(LU[ps[i]][k])*scales[ps[i]];

			if (biggest < size) {
				biggest     = size;  // biggest scales column element
				pivot_index = i;     // row index of this element
			}
		}

		if (biggest == 0) singular(SINGULAR_MATRIX);
		else {
			if (pivot_index != k) {
				// Exchange rows.
				int j = ps[k];
				ps[k] = ps[pivot_index];
				ps[pivot_index] = j;
			}

			pivot = LU[ps[k]][k];  // pivot element

			// Go down rest of rows.
			for (int i = k+1; i < n; i++) {
				mult = LU[ps[i]][k]/pivot;
				LU[ps[i]][k] = mult;

				if (mult != 0) {
					// Inner loop.
					for (int j = k+1; j < n; j++) {
						// Only the column subscript varies.
						LU[ps[i]][j] -= mult*LU[ps[k]][j];
					}
				}
			}
		}
	}

	// Check the bottom right element of the permuted matrix.
	if (LU[ps[n-1]][n-1] == 0) singular(SINGULAR_MATRIX);
}

void solve(const int n, double LU[][MAX_SIZE],
           const double b[], double x[], const int ps[MAX_SIZE]) {
	double dot;  // dot product

	// Ly = b : solve for y.
	for (int i = 0; i < n; i++) {
		dot = 0;
		for (int j = 0; j <= i-1; j++) dot += LU[ps[i]][j]*x[j];
		x[i] = b[ps[i]] - dot;
	}

	// Ux = y : solve for x.
	for (int i = n-1; i >= 0; i--) {
		dot = 0;
		for (int j = i+1; j < n; j++) dot += LU[ps[i]][j]*x[j];
		x[i] = (x[i] - dot)/LU[ps[i]][i];
	}
}

void singular(const ErrorCode code) {
	switch (code) {
		case ZERO_ROW:
			cout << "Matrix with zero row in decompose." << endl;
			break;
		case SINGULAR_MATRIX:
			cout << "Singular matrix in decompose." << endl;
			break;
		case NO_CONVERGENCE:
			cout << "No convergence in improve" << endl;
			break;
	}
}
#ifndef __ISFUNCTIONS_H_
#define __ISFUNCTIONS_H_

//Row check
void is_Row();
void is_RowM(Matrix* A);

//Column check
void is_Column();
void is_ColumnM(Matrix* A);

//Null check
void is_Null();
void is_NullM();

//Square check
void is_Square();
void is_SquareM(Matrix* A);

//Identity check
void is_Identity();
void is_IdentityM(Matrix* A);

//Diagonal check
void is_Diagonal();
void is_DiagonalM(Matrix* A);

//Scalar check
void is_Scalar();
void is_ScalarM(Matrix* A);

//Triangular check
void is_Triangular();
void is_TriangularM(Matrix* A);

//Symmetric check
void is_Symmetric();
void is_SymmetricM(Matrix* A);

//Antisymmetric check
void is_AntiSymmetric();
void is_AntiSymmetricM(Matrix* A);

//Invertible check
void is_Invertible();

#endif

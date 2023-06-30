#ifndef __ISFUNCTIONS_H_
#define __ISFUNCTIONS_H_

void is_Row();
void is_Column();

//Null check
void is_Null();
void is_NullM();

//Square check
void is_Square();
void is_SquareM(Matrix* A);

//Identity check
void is_Identity();
void is_IdentityM(Matrix* A);

//Elementary check
void is_Elementary();

//Invertible check
void is_Invertible();

//Diagonal check
void is_Diagonal();

//Scalar check
void is_Scalar();

//Upper Triangle check
void is_Upper_Triangle();

//Stictly Upper Triangle check
void is_Strictly_Upper_Triangle();

//Lower triangle check
void is_Lower_Triangle();

//Strictly Lower Triangle check
void is_Strictly_Lower_Triangle();

//Symmetric check
void is_Symmetric();

//Antisymmetric check
void is_AntiSymmetric();

#endif

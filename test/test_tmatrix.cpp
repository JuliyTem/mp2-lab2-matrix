#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> _m(m);

	EXPECT_EQ(m, _m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> _m(m);

	m[0][3] = 10;

	EXPECT_NE(m, _m);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);

	EXPECT_EQ(5, m.GetSize());

}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);

	m[0][3] = 3;

	EXPECT_EQ(m[0][3], 3);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-1] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[6][6] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(10);

	m[0][6] = 5;

	m = m;

	EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> w(10);

	m[0][5] = 5;
	m[0][6] = 6;
	w[0][5] = 15;
	w[0][6] = 16;

	m = w;

	EXPECT_EQ(m, w);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	TMatrix<int> w(7);

	m = w;

	EXPECT_EQ(7, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5);
	TMatrix<int> w(7);

	m = w;

	EXPECT_EQ(m, w);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(10);
	TMatrix<int> w(10);

	m[5][6] = 5;
	w[5][6] = 5;

	EXPECT_EQ(m, w);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(10);
	
	m[5][6] = 56;
	
	EXPECT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(10);
	TMatrix<int> w(8);

	m[0][6] = 5;
	w[0][6] = 5;

	EXPECT_NE(m, w);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> w(10);
	TMatrix<int> q(10);

	q[2][3] = 23;
	q[3][4] = 34;

	m[2][3] = 123;
	m[3][4] = 134;

	w[2][3] = 223;
	w[3][4] = 234;

	q = m + w;
	m = m + w;

	EXPECT_EQ(q, m);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> w(11);

	ASSERT_ANY_THROW(m = m + w);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> w(10);
	TMatrix<int> q(10);

	q[2][3] = 23;
	q[3][4] = 34;

	m[2][3] = 123;
	m[3][4] = 134;

	w[2][3] = 223;
	w[3][4] = 234;

	q = m - w;
	m = m - w;

	EXPECT_EQ(q, m);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(10);
	TMatrix<int> w(11);

	ASSERT_ANY_THROW(m = m - w);
}


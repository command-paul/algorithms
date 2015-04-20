/*!
 * \file search.h
 *
 * \author Vijay Nandwani(isthegeek)
 * \date 17 April 2015
 *
 * This file contains function declarations for various types of searching functions
 *
 *\todo Add time complexity for each sort function in their documentation
 */
#ifndef SEARCH_H_
#define SEARCH_H_


/*!
 * \brief Search an array linearly
 *
 * Example Usage: int arr[] = {4, 5, 20, 6, 2, 3, 12, 1};linearSearch(arr, 6);
 *
 * \param[in] [int *arr] [integer array to search]
 * \param[in] [int elem] [element to search]
 * \param[in] [int len] [length of array]
 * \param[out] [int] [-1 if found else the index of the element]
 * \return [int]
 * \sa None
 * \note None
 * \warning None
 */
int linearSearch(int *arr, int elem, int len);

/*!
 * \brief Binary search for integer array
 *
 * Example Usage: int arr[] = {4, 5, 20, 6, 2, 3, 12, 1};binarySearch(arr, 6);
 *
 * \param[in] [int *arr] [integer array to search]
 * \param[in] [int elem] [element to search]
 * \param[in] [int len] [length of array]
 * \param[out] [int] [-1 if found else the index of the element]
 * \return [int]
 * \sa None
 * \note None
 * \warning None
 */
int binarySearch(int *arr, int elem, int len);
#endif

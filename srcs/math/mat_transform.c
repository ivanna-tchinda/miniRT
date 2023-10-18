/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:49:30 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/18 19:36:38 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

void	translate_matrix(t_mat4 *mat, double x, double y, double z)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = 1;
	(*mat)[1][1] = 1;
	(*mat)[2][2] = 1;
	(*mat)[3][3] = 1;
	(*mat)[0][3] = x;
	(*mat)[1][3] = y;
	(*mat)[2][3] = z;
}

/**
 * Initialize the scaling matrix
 * mat The matrix to be initialized
 * x The value along the x-axis to be scaled.
 * y The value along the y-axis to be scaled.
 * z The value along the z-axis to be scaled.
 */
void	scaling_matrix(t_mat4 *mat, double x, double y, double z)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = x;
	(*mat)[1][1] = y;
	(*mat)[2][2] = z;
	(*mat)[3][3] = 1;
}

/**
 *Initialize the matrix for rotation along x-axis
 * mat The matrix to be initialized
 * r angle in radians
 */
void	rotation_matrix_x(t_mat4 *mat, double r)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = 1;
	(*mat)[1][1] = cos(r);
	(*mat)[1][2] = sin(r) * -1;
	(*mat)[2][1] = sin(r);
	(*mat)[2][2] = cos(r);
	(*mat)[3][3] = 1;
}

/**
 * Initialize the matrix for rotation along y-axis
 * mat The matrix to be initialized
 *  r angle in radians
 */
void	rotation_matrix_y(t_mat4 *mat, double r)
{
	ft_bzero(mat, sizeof(t_mat4));
	(*mat)[0][0] = cos(r);
	(*mat)[0][2] = sin(r);
	(*mat)[1][1] = 1;
	(*mat)[2][0] = sin(r) * -1;
	(*mat)[2][2] = cos(r);
	(*mat)[3][3] = 1;
}

/**
 * @brief Initialize the matrix for rotation along z-axis
 * @param mat The matrix to be initialized
 * @param r angle in radians
 */
// we are not using this
// void	rotation_matrix_z(t_mat4 *mat, double r)
// {
// 	ft_bzero(mat, sizeof(t_mat4));
// 	(*mat)[0][0] = cos(r);
// 	(*mat)[0][1] = sin(r) * -1;
// 	(*mat)[1][0] = sin(r);
// 	(*mat)[1][1] = cos(r);
// 	(*mat)[2][2] = 1;
// 	(*mat)[3][3] = 1;
// }

void	axis_angle(t_mat4 *rot_mat, const t_vector *ax, double angle)
{
	(*rot_mat)[0][0] = cos(angle) + ax->x * ax->x * (1 - cos(angle));
	(*rot_mat)[0][1] = ax->x * ax->y * (1 - cos(angle)) - ax->z * sin(angle);
	(*rot_mat)[0][2] = ax->x * ax->z * (1 - cos(angle)) + ax->y * sin(angle);
	(*rot_mat)[0][3] = 0;
	(*rot_mat)[1][0] = ax->x * ax->y * (1 - cos(angle)) + ax->z * sin(angle);
	(*rot_mat)[1][1] = cos(angle) + ax->y * ax->y * (1 - cos(angle));
	(*rot_mat)[1][2] = ax->y * ax->z * (1 - cos(angle)) - ax->x * sin(angle);
	(*rot_mat)[1][3] = 0;
	(*rot_mat)[2][0] = ax->z * ax->x * (1 - cos(angle)) - ax->y * sin(angle);
	(*rot_mat)[2][1] = ax->z * ax->y * (1 - cos(angle)) + ax->x * sin(angle);
	(*rot_mat)[2][2] = cos(angle) + ax->z * ax->z * (1 - cos(angle));
	(*rot_mat)[2][3] = 0;
	(*rot_mat)[3][0] = 0;
	(*rot_mat)[3][1] = 0;
	(*rot_mat)[3][2] = 0;
	(*rot_mat)[3][3] = 1;
}

/* https://en.wikipedia.org/wiki/Rotation_matrix */

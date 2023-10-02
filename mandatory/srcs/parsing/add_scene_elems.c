#include "miniRT.h"

int add_ambient(t_data *data, char **elems)
{
    t_ambient ambient;
    int ret;
    (void)ret;

    ft_bzero(&ambient, sizeof(t_ambient));
    data->scene.nb_amb++;
    if(data->scene.nb_amb > 1)
        return(ret = write(STDIN_FILENO, ERR_NB_AMBIENT, 41), 1);
    if(ft_tabsize(elems) != 3 || is_void(elems[2][0]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_ratio(elems[1]) || check_color(elems[2]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    ambient.ratio = ft_atod(elems[1]);
    ambient.color = get_color(elems[2]);
    data->scene.ambient = ambient;
    return(0);
}

int add_light(t_data *data, char **elems)
{
    t_light light;
    int ret;
    (void)ret;

    ft_bzero(&light, sizeof(t_light));
    data->scene.nb_light++;
    if(data->scene.nb_light > 1)
        return(ret = write(STDIN_FILENO, ERR_NB_LIGHT, 33), 1);
    if(ft_tabsize(elems) != 4 || is_void(elems[3][0]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1])|| check_ratio(elems[2]) || check_color(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    light.position = get_position(elems[1]);
    light.ratio = ft_atod(elems[2]);
    light.color = get_color(elems[3]);
    data->scene.light = light;
    return(0);
}

int add_camera(t_data *data, char **elems)
{
    t_camera camera;
    int ret;
    (void)ret;

    ft_bzero(&camera, sizeof(t_camera));
    data->scene.nb_cam++;
    if(data->scene.nb_cam > 1)
        return(ret = write(STDIN_FILENO, ERR_NB_CAMERA, 34), 1);
    if(ft_tabsize(elems) != 4 || is_void(elems[3][0]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1]) || check_vector(elems[2]) || check_fov(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    camera.position = get_position(elems[1]);
    camera.vector = get_position(elems[2]);
    camera.fov = ft_atoi(elems[3]) * DEG_2_RAD;
    data->scene.camera = camera;
    return(0);
}

//fov in redian to easy use
#ifndef BABELTRACE2_GRAPH_COMPONENT_CLASS_CONST_H
#define BABELTRACE2_GRAPH_COMPONENT_CLASS_CONST_H

/*
 * Copyright (c) 2010-2019 EfficiOS Inc. and Linux Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __BT_IN_BABELTRACE_H
# error "Please include <babeltrace2/babeltrace.h> instead."
#endif

#include <babeltrace2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bt_component_class_type {
	BT_COMPONENT_CLASS_TYPE_SOURCE = 0,
	BT_COMPONENT_CLASS_TYPE_FILTER = 1,
	BT_COMPONENT_CLASS_TYPE_SINK = 2,
} bt_component_class_type;

extern const char *bt_component_class_get_name(
		const bt_component_class *component_class);

extern const char *bt_component_class_get_description(
		const bt_component_class *component_class);

extern const char *bt_component_class_get_help(
		const bt_component_class *component_class);

extern bt_component_class_type bt_component_class_get_type(
		const bt_component_class *component_class);

static inline
bt_bool bt_component_class_is_source(
		const bt_component_class *component_class)
{
	return bt_component_class_get_type(component_class) ==
		BT_COMPONENT_CLASS_TYPE_SOURCE;
}

static inline
bt_bool bt_component_class_is_filter(
		const bt_component_class *component_class)
{
	return bt_component_class_get_type(component_class) ==
		BT_COMPONENT_CLASS_TYPE_FILTER;
}

static inline
bt_bool bt_component_class_is_sink(
		const bt_component_class *component_class)
{
	return bt_component_class_get_type(component_class) ==
		BT_COMPONENT_CLASS_TYPE_SINK;
}

extern void bt_component_class_get_ref(
		const bt_component_class *component_class);

extern void bt_component_class_put_ref(
		const bt_component_class *component_class);

#define BT_COMPONENT_CLASS_PUT_REF_AND_RESET(_var)	\
	do {						\
		bt_component_class_put_ref(_var);	\
		(_var) = NULL;				\
	} while (0)

#define BT_COMPONENT_CLASS_MOVE_REF(_var_dst, _var_src)	\
	do {						\
		bt_component_class_put_ref(_var_dst);	\
		(_var_dst) = (_var_src);		\
		(_var_src) = NULL;			\
	} while (0)

#ifdef __cplusplus
}
#endif

#endif /* BABELTRACE2_GRAPH_COMPONENT_CLASS_CONST_H */

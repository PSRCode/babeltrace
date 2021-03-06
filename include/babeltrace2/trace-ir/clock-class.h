#ifndef BABELTRACE2_TRACE_IR_CLOCK_CLASS_H
#define BABELTRACE2_TRACE_IR_CLOCK_CLASS_H

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

#include <stdint.h>

#include <babeltrace2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

extern bt_clock_class *bt_clock_class_create(bt_self_component *self_comp);

extern bt_value *bt_clock_class_borrow_user_attributes(
		bt_clock_class *clock_class);

extern void bt_clock_class_set_user_attributes(
		bt_clock_class *clock_class, const bt_value *user_attributes);

typedef enum bt_clock_class_set_name_status {
	BT_CLOCK_CLASS_SET_NAME_STATUS_MEMORY_ERROR	= __BT_FUNC_STATUS_MEMORY_ERROR,
	BT_CLOCK_CLASS_SET_NAME_STATUS_OK		= __BT_FUNC_STATUS_OK,
} bt_clock_class_set_name_status;

extern bt_clock_class_set_name_status bt_clock_class_set_name(
		bt_clock_class *clock_class, const char *name);

typedef enum bt_clock_class_set_description_status {
	BT_CLOCK_CLASS_SET_DESCRIPTION_STATUS_MEMORY_ERROR	= __BT_FUNC_STATUS_MEMORY_ERROR,
	BT_CLOCK_CLASS_SET_DESCRIPTION_STATUS_OK		= __BT_FUNC_STATUS_OK,
} bt_clock_class_set_description_status;

extern bt_clock_class_set_description_status bt_clock_class_set_description(
		bt_clock_class *clock_class, const char *description);

extern void bt_clock_class_set_frequency(bt_clock_class *clock_class,
		uint64_t freq);

extern void bt_clock_class_set_precision(bt_clock_class *clock_class,
		uint64_t precision);

extern void bt_clock_class_set_offset(bt_clock_class *clock_class,
		int64_t seconds, uint64_t cycles);

extern void bt_clock_class_set_origin_is_unix_epoch(bt_clock_class *clock_class,
		bt_bool origin_is_unix_epoch);

extern void bt_clock_class_set_uuid(bt_clock_class *clock_class,
		bt_uuid uuid);

#ifdef __cplusplus
}
#endif

#endif /* BABELTRACE2_TRACE_IR_CLOCK_CLASS_H */

#ifndef _BABELTRACE_ITERATOR_INTERNAL_H
#define _BABELTRACE_ITERATOR_INTERNAL_H

/*
 * BabelTrace
 *
 * Internal iterator header
 *
 * Copyright 2010-2011 EfficiOS Inc. and Linux Foundation
 *
 * Author: Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
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
 */

/*
 * struct babeltrace_iter: data structure representing an iterator on a trace
 * collection.
 */
struct babeltrace_iter {
	struct ptr_heap *stream_heap;
	struct trace_collection *tc;
	struct trace_collection_pos *end_pos;
	GArray *callbacks;				/* Array of struct bt_stream_callbacks */
	struct bt_callback_chain main_callbacks;	/* For all events */
	/*
	 * Flag indicating if dependency graph needs to be recalculated.
	 * Set by babeltrace_iter_add_callback(), and checked (and
	 * cleared) by upon entry into babeltrace_iter_read_event().
	 * babeltrace_iter_read_event() is responsible for calling dep
	 * graph calculation if it sees this flag set.
	 */
	int recalculate_dep_graph;
	/*
	 * Array of pointers to struct bt_dependencies, for garbage
	 * collection. We're not using a linked list here because each
	 * struct bt_dependencies can belong to more than one
	 * babeltrace_iter.
	 */
	GPtrArray *dep_gc;
};

#endif /* _BABELTRACE_ITERATOR_INTERNAL_H */

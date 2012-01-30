#ifndef _BABELTRACE_INTERNAL_H
#define _BABELTRACE_INTERNAL_H

#include <stdio.h>
#include <glib.h>
#include <stdint.h>

extern int babeltrace_verbose, babeltrace_debug;

#define printf_verbose(fmt, args...)					\
	do {								\
		if (babeltrace_verbose)					\
			fprintf(stdout, "[verbose] " fmt, ## args);	\
	} while (0)

#define printf_debug(fmt, args...)					\
	do {								\
		if (babeltrace_debug)					\
			fprintf(stdout, "[debug] " fmt, ## args);	\
	} while (0)

#define likely(x)	__builtin_expect(!!(x), 1)
#define unlikely(x)	__builtin_expect(!!(x), 0)

struct trace_descriptor;
struct trace_collection {
	GPtrArray *array;	/* struct trace_descriptor */
	GHashTable *clocks;	/* struct ctf_clock */
	struct ctf_clock *single_clock;
};

extern int opt_all_field_names,
	opt_scope_field_names,
	opt_header_field_names,
	opt_context_field_names,
	opt_payload_field_names,
	opt_all_fields,
	opt_trace_field,
	opt_trace_domain_field,
	opt_trace_procname_field,
	opt_trace_vpid_field,
	opt_loglevel_field,
	opt_delta_field,
	opt_clock_raw,
	opt_clock_seconds,
	opt_clock_date,
	opt_clock_gmt;

extern uint64_t opt_clock_offset;

#endif

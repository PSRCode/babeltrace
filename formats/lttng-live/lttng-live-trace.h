
#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER babeltrace

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./formats/lttng-live/lttng-live-trace.h"

#if !defined(FORMATS_LTTNG_LIVE_LTTNG_LIVE_TRACE_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define FORMATS_LTTNG_LIVE_LTTNG_LIVE_TRACE_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(babeltrace, lttng_live_received_index,
    TP_ARGS(
        unsigned long, stream_id_arg,
        unsigned long, timestamp_begin_arg,
        unsigned long, timestamp_end_arg
    ),
    TP_FIELDS(
        ctf_integer(unsigned long, stream_id, stream_id_arg)
        ctf_integer(unsigned long, timestamp_begin, timestamp_begin_arg)
        ctf_integer(unsigned long, timestamp_end, timestamp_end_arg)
    )
)

#endif /* FORMATS_LTTNG_LIVE_LTTNG_LIVE_TRACE_H */

#include <lttng/tracepoint-event.h>

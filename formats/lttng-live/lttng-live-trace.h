
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

TRACEPOINT_EVENT(babeltrace, lttng_live_recv_enter,
    TP_ARGS(
        int, fd_arg,
        size_t, len_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(size_t, len, len_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, lttng_live_recv_leave,
    TP_ARGS(
        int, fd_arg,
        ssize_t, ret_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(ssize_t, ret, ret_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, lttng_live_send_enter,
    TP_ARGS(
        int, fd_arg,
        size_t, len_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(size_t, len, len_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, lttng_live_send_leave,
    TP_ARGS(
        int, fd_arg,
        ssize_t, ret_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(ssize_t, ret, ret_arg)
    )
)

TRACEPOINT_EVENT(babeltrace, sys_recv_enter,
    TP_ARGS(
        int, fd_arg,
        size_t, len_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(size_t, len, len_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, sys_recv_leave,
    TP_ARGS(
        int, fd_arg,
        ssize_t, ret_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(ssize_t, ret, ret_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, sys_send_enter,
    TP_ARGS(
        int, fd_arg,
        size_t, len_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(size_t, len, len_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, sys_send_leave,
    TP_ARGS(
        int, fd_arg,
        ssize_t, ret_arg
    ),
    TP_FIELDS(
        ctf_integer(int, fd, fd_arg)
        ctf_integer(ssize_t, ret, ret_arg)
    )
)

TRACEPOINT_EVENT(babeltrace, lttng_live_packet_seek_enter,
    TP_ARGS(), TP_FIELDS())
TRACEPOINT_EVENT(babeltrace, lttng_live_packet_seek_leave,
    TP_ARGS(), TP_FIELDS())

TRACEPOINT_EVENT(babeltrace, lttng_live_get_index_enter,
    TP_ARGS(), TP_FIELDS())
TRACEPOINT_EVENT(babeltrace, lttng_live_get_index_leave,
    TP_ARGS(
        int, ret_arg
    ),
    TP_FIELDS(
        ctf_integer(int, ret, ret_arg)
    )
)
TRACEPOINT_EVENT(babeltrace, lttng_live_get_index_reply,
    TP_ARGS(
        unsigned long, stream_id_arg,
        int, status_arg
    ),
    TP_FIELDS(
        ctf_integer(unsigned long, stream_id, stream_id_arg)
        ctf_integer(int, status, status_arg)
    )
)

TRACEPOINT_EVENT(babeltrace, lttng_live_get_data_packet_enter,
    TP_ARGS(), TP_FIELDS())
TRACEPOINT_EVENT(babeltrace, lttng_live_get_data_packet_leave,
    TP_ARGS(
        int, ret_arg
    ),
    TP_FIELDS(
        ctf_integer(int, ret, ret_arg)
    )
)

#endif /* FORMATS_LTTNG_LIVE_LTTNG_LIVE_TRACE_H */

#include <lttng/tracepoint-event.h>

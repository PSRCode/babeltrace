#
# Copyright (C) 2019 EfficiOS Inc.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; only version 2
# of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#

import bt2


def to_string(p):
    # Print BT values in a predictable way (the order of map entries) and with
    # additional information (u suffix to differentiate unsigned integers from
    # signed integers).

    if type(p) is bt2.ArrayValue:
        s = '[{}]'.format(', '.join([to_string(x) for x in p]))
    elif type(p) is bt2.MapValue:
        s = '{{{}}}'.format(
            ', '.join([k + '=' + to_string(p[k]) for k in sorted(p.keys())])
        )
    elif type(p) is bt2.UnsignedIntegerValue:
        s = str(p) + 'u'
    else:
        s = str(p)

    return s


@bt2.plugin_component_class
class SinkThatPrintsParams(bt2._UserSinkComponent):
    def __init__(self, config, params, obj):
        self._add_input_port('in')
        print(to_string(params))

    def _user_consume(self):
        raise bt2.Stop


bt2.register_plugin(__name__, "params")

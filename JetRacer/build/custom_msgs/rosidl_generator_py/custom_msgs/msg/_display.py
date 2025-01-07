# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/Display.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Display(type):
    """Metaclass of message 'Display'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.Display')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__display
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__display
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__display
            cls._TYPE_SUPPORT = module.type_support_msg__msg__display
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__display

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Display(metaclass=Metaclass_Display):
    """Message class 'Display'."""

    __slots__ = [
        '_line1',
        '_line2',
        '_line3',
        '_line4',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'line1': 'string',
        'line2': 'string',
        'line3': 'string',
        'line4': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.line1 = kwargs.get('line1', str())
        self.line2 = kwargs.get('line2', str())
        self.line3 = kwargs.get('line3', str())
        self.line4 = kwargs.get('line4', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.line1 != other.line1:
            return False
        if self.line2 != other.line2:
            return False
        if self.line3 != other.line3:
            return False
        if self.line4 != other.line4:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def line1(self):
        """Message field 'line1'."""
        return self._line1

    @line1.setter
    def line1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'line1' field must be of type 'str'"
        self._line1 = value

    @builtins.property
    def line2(self):
        """Message field 'line2'."""
        return self._line2

    @line2.setter
    def line2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'line2' field must be of type 'str'"
        self._line2 = value

    @builtins.property
    def line3(self):
        """Message field 'line3'."""
        return self._line3

    @line3.setter
    def line3(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'line3' field must be of type 'str'"
        self._line3 = value

    @builtins.property
    def line4(self):
        """Message field 'line4'."""
        return self._line4

    @line4.setter
    def line4(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'line4' field must be of type 'str'"
        self._line4 = value

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/display__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `line1`
// Member `line2`
// Member `line3`
// Member `line4`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_msgs__msg__Display__init(custom_msgs__msg__Display * msg)
{
  if (!msg) {
    return false;
  }
  // line1
  if (!rosidl_runtime_c__String__init(&msg->line1)) {
    custom_msgs__msg__Display__fini(msg);
    return false;
  }
  // line2
  if (!rosidl_runtime_c__String__init(&msg->line2)) {
    custom_msgs__msg__Display__fini(msg);
    return false;
  }
  // line3
  if (!rosidl_runtime_c__String__init(&msg->line3)) {
    custom_msgs__msg__Display__fini(msg);
    return false;
  }
  // line4
  if (!rosidl_runtime_c__String__init(&msg->line4)) {
    custom_msgs__msg__Display__fini(msg);
    return false;
  }
  return true;
}

void
custom_msgs__msg__Display__fini(custom_msgs__msg__Display * msg)
{
  if (!msg) {
    return;
  }
  // line1
  rosidl_runtime_c__String__fini(&msg->line1);
  // line2
  rosidl_runtime_c__String__fini(&msg->line2);
  // line3
  rosidl_runtime_c__String__fini(&msg->line3);
  // line4
  rosidl_runtime_c__String__fini(&msg->line4);
}

bool
custom_msgs__msg__Display__are_equal(const custom_msgs__msg__Display * lhs, const custom_msgs__msg__Display * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // line1
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->line1), &(rhs->line1)))
  {
    return false;
  }
  // line2
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->line2), &(rhs->line2)))
  {
    return false;
  }
  // line3
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->line3), &(rhs->line3)))
  {
    return false;
  }
  // line4
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->line4), &(rhs->line4)))
  {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__Display__copy(
  const custom_msgs__msg__Display * input,
  custom_msgs__msg__Display * output)
{
  if (!input || !output) {
    return false;
  }
  // line1
  if (!rosidl_runtime_c__String__copy(
      &(input->line1), &(output->line1)))
  {
    return false;
  }
  // line2
  if (!rosidl_runtime_c__String__copy(
      &(input->line2), &(output->line2)))
  {
    return false;
  }
  // line3
  if (!rosidl_runtime_c__String__copy(
      &(input->line3), &(output->line3)))
  {
    return false;
  }
  // line4
  if (!rosidl_runtime_c__String__copy(
      &(input->line4), &(output->line4)))
  {
    return false;
  }
  return true;
}

custom_msgs__msg__Display *
custom_msgs__msg__Display__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Display * msg = (custom_msgs__msg__Display *)allocator.allocate(sizeof(custom_msgs__msg__Display), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__Display));
  bool success = custom_msgs__msg__Display__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__Display__destroy(custom_msgs__msg__Display * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__Display__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__Display__Sequence__init(custom_msgs__msg__Display__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Display * data = NULL;

  if (size) {
    data = (custom_msgs__msg__Display *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__Display), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__Display__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__Display__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__Display__Sequence__fini(custom_msgs__msg__Display__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__Display__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__Display__Sequence *
custom_msgs__msg__Display__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Display__Sequence * array = (custom_msgs__msg__Display__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__Display__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__Display__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__Display__Sequence__destroy(custom_msgs__msg__Display__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__Display__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__Display__Sequence__are_equal(const custom_msgs__msg__Display__Sequence * lhs, const custom_msgs__msg__Display__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__Display__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__Display__Sequence__copy(
  const custom_msgs__msg__Display__Sequence * input,
  custom_msgs__msg__Display__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__Display);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__Display * data =
      (custom_msgs__msg__Display *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__Display__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__Display__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__Display__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

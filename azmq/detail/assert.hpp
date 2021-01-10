#pragma once

# include <assert.h> // .h to support old libraries w/o <cassert> - effect is the same

# define AZMQ_ASSERT(expr) assert(expr)
# define AZMQ_ASSERT_MSG(expr, msg) assert((expr)&&(msg))
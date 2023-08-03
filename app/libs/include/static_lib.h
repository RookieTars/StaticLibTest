#ifndef SRCS_LIBS_STATIC_LIB_STATIC_LIB_H_
#define SRCS_LIBS_STATIC_LIB_STATIC_LIB_H_

class User
{
public:
    User() = default;
    ~User() = default;
    int Add(int a, int b);
};

int user_add(int a, int b);

#endif // SRCS_LIBS_STATIC_LIB_STATIC_LIB_H_
/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.6.3
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // C:/Users/ASUS/Desktop/Lab Project/CSCE1102-LabProject/MEDAD/UserData.txt
  0x0,0x0,0x0,0x33,
  0x61,
  0x64,0x6d,0x69,0x6e,0x20,0x41,0x79,0x6c,0x61,0x53,0x61,0x6c,0x65,0x68,0x20,0x61,
  0x79,0x6c,0x61,0x31,0x32,0x33,0x34,0xd,0xa,0x63,0x75,0x73,0x74,0x6f,0x6d,0x65,
  0x72,0x20,0x61,0x79,0x6c,0x61,0x53,0x20,0x61,0x79,0x6c,0x61,0x31,0x32,0x33,0x34,
  0xd,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // UsersInfo
  0x0,0x9,
  0xc,0x97,0x7d,0xef,
  0x0,0x55,
  0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x73,0x0,0x49,0x0,0x6e,0x0,0x66,0x0,0x6f,
    // UserData.txt
  0x0,0xc,
  0x3,0x33,0xd6,0xb4,
  0x0,0x55,
  0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x44,0x0,0x61,0x0,0x74,0x0,0x61,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/UsersInfo
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/UsersInfo/UserData.txt
  0x0,0x0,0x0,0x18,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x8f,0x32,0x1e,0x16,0xe7,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_UserData)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_UserData)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_UserData)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_UserData)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_UserData)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_UserData)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
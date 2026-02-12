
#ifndef R66_EXPORT_H
#define R66_EXPORT_H

#ifdef R66_STATIC_DEFINE
#  define R66_EXPORT
#  define R66_NO_EXPORT
#else
#  ifndef R66_EXPORT
#    ifdef R66_EXPORTS
        /* We are building this library */
#      define R66_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define R66_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef R66_NO_EXPORT
#    define R66_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef R66_DEPRECATED
#  define R66_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef R66_DEPRECATED_EXPORT
#  define R66_DEPRECATED_EXPORT R66_EXPORT R66_DEPRECATED
#endif

#ifndef R66_DEPRECATED_NO_EXPORT
#  define R66_DEPRECATED_NO_EXPORT R66_NO_EXPORT R66_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef R66_NO_DEPRECATED
#    define R66_NO_DEPRECATED
#  endif
#endif

#endif /* R66_EXPORT_H */

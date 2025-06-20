/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.30 from the
 * contents of Whirlpool.xs. Do not edit this file, edit Whirlpool.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
#include "../whirlpool-algorithm.h"

#define CLASS klass

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"


#line 20 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 164 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"

XS_EUPXS(XS_Utils__Whirlpool_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Whirlpool_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "klass");
    {
	char *	klass = (char *)SvPV_nolen(ST(0))
;
	WP_Struct *	RETVAL;
#line 17 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
	RETVAL = WP_Create();
#line 178 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
	    sv_setref_pv( RETVALSV, CLASS, (void*)RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Utils__Whirlpool_init); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Whirlpool_init)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wp");
    {
	WP_Struct *	wp;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		wp = (WP_Struct *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "Utils::Whirlpool::init() -- wp is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 25 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
	WP_Init(wp);
#line 208 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Utils__Whirlpool_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Whirlpool_add)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "wp, data");
    {
	WP_Struct *	wp;
	SV *	data = ST(1)
;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		wp = (WP_Struct *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "Utils::Whirlpool::add() -- wp is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 32 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
	if (data != NULL && SvOK(data)) {
		STRLEN len;
		char *bytes;

		bytes = SvPV(data, len);
		WP_Add((const unsigned char * const) bytes, len * 8, wp);
	}
#line 240 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Utils__Whirlpool_finalize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Whirlpool_finalize)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wp");
    {
	WP_Struct *	wp;
	SV *	RETVAL;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		wp = (WP_Struct *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "Utils::Whirlpool::finalize() -- wp is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 44 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
	unsigned char hash[WP_DIGEST_SIZE];
#line 265 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
#line 46 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
	WP_Finalize(wp, hash);
	RETVAL = newSVpvn((const char *) hash, WP_DIGEST_SIZE);
#line 269 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
	RETVAL = sv_2mortal(RETVAL);
	ST(0) = RETVAL;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Utils__Whirlpool_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Whirlpool_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wp");
    {
	WP_Struct *	wp;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		wp = (WP_Struct *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "Utils::Whirlpool::DESTROY() -- wp is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 55 "src\\\\auto\\\\XSTools\\\\utils\\\\perl\\\\Whirlpool.xs"
	WP_Free(wp);
#line 295 "src\\auto\\XSTools\\utils\\perl\\Whirlpool.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Utils__Whirlpool); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Utils__Whirlpool)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSXSAPIVERCHK;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5)
    XS_VERSION_BOOTCHECK;
#  ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#  endif
#endif

        (void)newXSproto_portable("Utils::Whirlpool::new", XS_Utils__Whirlpool_new, file, "$");
        (void)newXSproto_portable("Utils::Whirlpool::init", XS_Utils__Whirlpool_init, file, "$");
        (void)newXSproto_portable("Utils::Whirlpool::add", XS_Utils__Whirlpool_add, file, "$$");
        (void)newXSproto_portable("Utils::Whirlpool::finalize", XS_Utils__Whirlpool_finalize, file, "$");
        (void)newXSproto_portable("Utils::Whirlpool::DESTROY", XS_Utils__Whirlpool_DESTROY, file, "$");
#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}


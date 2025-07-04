/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.30 from the
 * contents of PaddedPackets.xs. Do not edit this file, edit PaddedPackets.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "engine.h"


using namespace OpenKore::PaddedPackets;

static Engine engine;
static dword lastTargetId = 0;
static word sitPacketID = 0x89;
static word skillPacketID = 0x113;


#line 26 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
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

#line 170 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"

XS_EUPXS(XS_Network__PaddedPackets_createSitStand); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_createSitStand)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "packet, sit");
    {
	char *	packet = (char *)SvPV_nolen(ST(0))
;
	unsigned int	sit = (unsigned int)SvUV(ST(1))
;
	unsigned int	RETVAL;
	dXSTARG;
#line 25 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.addKey(lastTargetId);
	lastTargetId = 0;
	engine.addKey(sit ? 2 : 3);
	RETVAL = engine.encode((byte *) packet, sitPacketID);
#line 190 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Network__PaddedPackets_createAtk); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_createAtk)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "packet, targetId, ctrl");
    {
	char *	packet = (char *)SvPV_nolen(ST(0))
;
	unsigned int	targetId = (unsigned int)SvUV(ST(1))
;
	unsigned int	ctrl = (unsigned int)SvUV(ST(2))
;
	unsigned int	RETVAL;
	dXSTARG;
#line 38 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	ctrl = ctrl + 1; // Shut up compiler warning.
	engine.addKey(targetId);
	engine.addKey(7);
	RETVAL = engine.encode((byte *) packet, sitPacketID);
#line 217 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Network__PaddedPackets_createSkillUse); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_createSkillUse)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "packet, skillId, skillLv, targetId");
    {
	char *	packet = (char *)SvPV_nolen(ST(0))
;
	unsigned int	skillId = (unsigned int)SvUV(ST(1))
;
	unsigned int	skillLv = (unsigned int)SvUV(ST(2))
;
	unsigned int	targetId = (unsigned int)SvUV(ST(3))
;
	unsigned int	RETVAL;
	dXSTARG;
#line 52 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.addKey(skillLv);
	engine.addKey(skillId);
	engine.addKey(targetId);
	RETVAL = engine.encode((byte *) packet, skillPacketID);
#line 246 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Network__PaddedPackets_setMapSync); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_setMapSync)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "mapSync");
    {
	unsigned int	mapSync = (unsigned int)SvUV(ST(0))
;
#line 63 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.setMapSync(mapSync);
#line 264 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Network__PaddedPackets_setSync); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_setSync)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "sync");
    {
	unsigned int	sync = (unsigned int)SvUV(ST(0))
;
#line 69 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.setSync(sync);
#line 281 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Network__PaddedPackets_setAccountId); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_setAccountId)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "accountId");
    {
	unsigned int	accountId = (unsigned int)SvUV(ST(0))
;
#line 75 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.setAccId(accountId);
#line 298 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Network__PaddedPackets_setPacket); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_setPacket)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "packet, packetLength, targetId");
    {
	char *	packet = (char *)SvPV_nolen(ST(0))
;
	unsigned int	packetLength = (unsigned int)SvUV(ST(1))
;
	unsigned int	targetId = (unsigned int)SvUV(ST(2))
;
#line 83 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.setPacket((byte *) packet, packetLength);
	lastTargetId = targetId;
#line 320 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Network__PaddedPackets_setPacketIDs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_setPacketIDs)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "sit, skill");
    {
	unsigned short	sit = (unsigned short)SvUV(ST(0))
;
	unsigned short	skill = (unsigned short)SvUV(ST(1))
;
#line 91 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	sitPacketID = sit;
	skillPacketID = skill;
#line 340 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Network__PaddedPackets_decodePacket); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_decodePacket)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "packet, keyCount");
    {
	char *	packet = (char *)SvPV_nolen(ST(0))
;
	unsigned int	keyCount = (unsigned int)SvUV(ST(1))
;
#line 99 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	engine.decode((byte *) packet, keyCount);
#line 359 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Network__PaddedPackets_getKey); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Network__PaddedPackets_getKey)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "keyIndex");
    {
	unsigned int	keyIndex = (unsigned int)SvUV(ST(0))
;
	unsigned int	RETVAL;
	dXSTARG;
#line 105 "src\\\\auto\\\\XSTools\\\\PaddedPackets\\\\PaddedPackets.xs"
	RETVAL = engine.getKey(keyIndex);
#line 378 "src\\auto\\XSTools\\PaddedPackets\\PaddedPackets.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Network__PaddedPackets); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Network__PaddedPackets)
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

        (void)newXSproto_portable("Network::PaddedPackets::createSitStand", XS_Network__PaddedPackets_createSitStand, file, "$$");
        (void)newXSproto_portable("Network::PaddedPackets::createAtk", XS_Network__PaddedPackets_createAtk, file, "$$$");
        (void)newXSproto_portable("Network::PaddedPackets::createSkillUse", XS_Network__PaddedPackets_createSkillUse, file, "$$$$");
        (void)newXSproto_portable("Network::PaddedPackets::setMapSync", XS_Network__PaddedPackets_setMapSync, file, "$");
        (void)newXSproto_portable("Network::PaddedPackets::setSync", XS_Network__PaddedPackets_setSync, file, "$");
        (void)newXSproto_portable("Network::PaddedPackets::setAccountId", XS_Network__PaddedPackets_setAccountId, file, "$");
        (void)newXSproto_portable("Network::PaddedPackets::setPacket", XS_Network__PaddedPackets_setPacket, file, "$$$");
        (void)newXSproto_portable("Network::PaddedPackets::setPacketIDs", XS_Network__PaddedPackets_setPacketIDs, file, "$$");
        (void)newXSproto_portable("Network::PaddedPackets::decodePacket", XS_Network__PaddedPackets_decodePacket, file, "$$");
        (void)newXSproto_portable("Network::PaddedPackets::getKey", XS_Network__PaddedPackets_getKey, file, "$");
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


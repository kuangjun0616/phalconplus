
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Model, phalconplus, base_model, zephir_get_internal_ce(SS("phalcon\\mvc\\model") TSRMLS_CC), phalconplus_base_model_method_entry, 0);

	zend_declare_property_null(phalconplus_base_model_ce, SL("ctime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("mtime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Model, initialize) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("notNullValidations"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_SELF(NULL, "setup", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "usedynamicupdate", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "keepsnapshots", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, getMessage) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfirstmessage", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage) {

	zval *_5 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_fast_count_int(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmessages", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		Z_SET_ISREF_P(_2);
		ZEPHIR_CALL_FUNCTION(&_3, "current", &_4, _2);
		Z_UNSET_ISREF_P(_2);
		zephir_check_call_status();
		zephir_get_strval(_5, _3);
		RETURN_CTOR(_5);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, getLastMessage) {

	zval *_5 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_fast_count_int(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmessages", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		Z_SET_ISREF_P(_2);
		ZEPHIR_CALL_FUNCTION(&_3, "end", &_4, _2);
		Z_UNSET_ISREF_P(_2);
		zephir_check_call_status();
		zephir_get_strval(_5, _3);
		RETURN_CTOR(_5);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, createBuilder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *source = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &alias_param);

	if (!alias_param) {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_STRING(alias, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}
	}


	if (!(ZEPHIR_IS_EMPTY(alias))) {
		ZEPHIR_INIT_VAR(source);
		zephir_create_array(source, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0);
		zephir_get_called_class(_0 TSRMLS_CC);
		zephir_array_update_string(&source, Z_STRVAL_P(alias), Z_STRLEN_P(alias), &_0, PH_COPY);
	} else {
		ZEPHIR_INIT_NVAR(source);
		zephir_get_called_class(source TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _1, "createbuilder", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "from", NULL, source);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *className, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, &_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("ctime"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("ctime"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("mtime"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, afterFetch) {



}

PHP_METHOD(PhalconPlus_Base_Model, beforeSave) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, &_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("mtime"), _1 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}




class GeneratorConfig:
    def __init__(self, 
                 cci_class_name, cci_prefix, cci_conversion_function, cci_wrapper_type,
                 jni_package, jni_class_name,
                 java_class_name, unit_test_origin_package, unit_test_type_name):
        self.cci_class_name = cci_class_name
        self.cci_prefix = cci_prefix
        self.cci_conversion_function = cci_conversion_function
        self.cci_wrapper_type = cci_wrapper_type
        self.cci_overriden_function_bodies = {}
        
        self.jni_package = jni_package
        self.full_jni_package = jni_package
        self.jni_class_name = jni_class_name
        self.include_jni_in_method_name = False
        
        self.java_class_name = java_class_name
        self.unit_test_origin_package = unit_test_origin_package
        self.unit_test_type_name = unit_test_type_name
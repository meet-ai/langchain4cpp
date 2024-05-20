
#define PROPERTY(type, name, default_value)         \
 private:                                           \
    type name = default_value;                      \
                                                    \
 public:                                            \
    const type& get_##name() const { return name; } \
    void set_##name(const type& value) { name = value; }

#define BUILDER_WITH(typebuilder, typefield, field_class_instance, field) \
    typebuilder& with_##field(const typefield& value) {                   \
        field_class_instance->field = value;                              \
        return *this;                                                     \
    }

//    AnthropicClientBuilder& log_response(bool log_resp) {
//        client->set_log_responses(log_resp);
//        return (*this);
//    }
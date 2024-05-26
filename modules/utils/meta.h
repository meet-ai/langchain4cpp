
#define PROPERTY(type, name, default_value)         \
 private:                                           \
    type name = default_value;                      \
                                                    \
 public:                                            \
    const type& get_##name() const { return name; } \
    void set_##name(const type& value) { name = value; }

#define BUILDER_WITH(builder_class, field_type, to_build_instance_ptr, field) \
    builder_class& with_##field(const field_type& value) {                    \
        to_build_instance_ptr->field = value;                                 \
        return *this;                                                         \
    }

//    AnthropicClientBuilder& log_response(bool log_resp) {
//        client->set_log_responses(log_resp);
//        return (*this);
//    }
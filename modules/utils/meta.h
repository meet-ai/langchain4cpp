
#define PROPERTY(type, name,default_value) \
private: \
    type name=default_value; \
public: \
    const type& get_##name() const { return name; } \
    void set_##name(const type& value) { name = value; }

#define BUILD_WITH(type, name,default_value) \
    const type& get_##name() const { return name; } \
    void set_##name(const type& value) { name = value; }
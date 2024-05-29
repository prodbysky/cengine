#include <functional>
#include <string>
namespace CEngine {
    enum class EventType {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScroll,
        ApplicationUpdate,
        ApplicationTick,
        ApplicationRender,
    };

    // For event filtering for eg. when logging events
    enum EventCategory {
        EventCategoryNone        = 0,
        EventCategoryWindow      = 1 << 0,
        EventCategoryInput       = 1 << 1,
        EventCategoryKeyboard    = 1 << 2,
        EventCategoryMouse       = 1 << 3,
        EventCategoryMouseButton = 1 << 4,
    };

#define EVENT_TYPE(type)                                                       \
    static EventType GetStaticType() { return type; }                          \
    virtual EventType GetType() const override { return GetStaticType(); }     \
    virtual const char* GetName() const override { return #type; }

#define EVENT_CATEGORY(category)                                               \
    virtual int GetCategories() const override { return category; }

    class Event {
    public:
        virtual EventType GetType() const   = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategories() const   = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool InCategory(EventCategory category) {
            return GetCategories() & category;
        }

    public:
        bool handled = false;
    };

    class EventSender {
        template <class T> using EventFunc = std::function<bool(T&)>;

    public:
        EventSender(Event& event) : event(event) {}

        template <class T> bool Send(EventFunc<T> func) {
            if (event.GetType() != T::GetStaticType()) {
                return false;
            }
            event.handled = func(*(T*) &event);
            return true;
        }

    private:
        Event& event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }

} // namespace CEngine

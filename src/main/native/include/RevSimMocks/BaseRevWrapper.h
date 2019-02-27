#ifndef SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_BASEREVWRAPPER_H_
#define SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_BASEREVWRAPPER_H_

#include <cstring>
#include <string>

template <typename T>
void PoplateReceiveResults(uint8_t* buffer, T* value, uint32_t& offset)
{
    std::memcpy(value, &buffer[offset], sizeof(*value));
    offset += sizeof(*value);
}

namespace SnobotSim
{

class BaseRevWrapper
{
public:
    virtual ~BaseRevWrapper()
    {
    }

    virtual void Receive(const std::string& aName, uint8_t* aBuffer, int aSize) = 0;
    virtual void Send(const std::string& aName, uint8_t* aBuffer, int aSize) = 0;

    void Send(const std::string& aName)
    {
        uint8_t buffer[1];
        Send(aName, buffer, 1);
    }

    template <typename T0>
    void Send(const std::string& aName, T0& param0)
    {
        int size = sizeof(T0);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1>
    void Send(const std::string& aName, T0& param0, T1& param1)
    {
        int size = sizeof(T0) + sizeof(T1);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1, typename T2>
    void Send(const std::string& aName, T0& param0, T1& param1, T2& param2)
    {
        int size = sizeof(T0) + sizeof(T1) + sizeof(T2);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        PushValue(buffer, param2, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1, typename T2, typename T3>
    void Send(const std::string& aName, T0& param0, T1& param1, T2& param2,
            T3& param3)
    {
        int size = sizeof(T0) + sizeof(T1) + sizeof(T2) + sizeof(T3);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        PushValue(buffer, param2, offset);
        PushValue(buffer, param3, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    void Send(const std::string& aName, T0& param0, T1& param1, T2& param2,
            T3& param3, T4& param4)
    {
        int size = sizeof(T0) + sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        PushValue(buffer, param2, offset);
        PushValue(buffer, param3, offset);
        PushValue(buffer, param4, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void Send(const std::string& aName, T0& param0, T1& param1, T2& param2,
            T3& param3, T4& param4, T5& param5)
    {
        int size = sizeof(T0) + sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        PushValue(buffer, param2, offset);
        PushValue(buffer, param3, offset);
        PushValue(buffer, param4, offset);
        PushValue(buffer, param5, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void Send(const std::string& aName, T0& param0, T1& param1, T2& param2,
            T3& param3, T4& param4, T5& param5, T6& param6)
    {
        int size = sizeof(T0) + sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5) + sizeof(T6);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        PushValue(buffer, param2, offset);
        PushValue(buffer, param3, offset);
        PushValue(buffer, param4, offset);
        PushValue(buffer, param5, offset);
        PushValue(buffer, param6, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
            typename T7, typename T8, typename T9, typename T10, typename T11>
    void Send(const std::string& aName, T0& param0, T1& param1, T2& param2,
            T3& param3, T4& param4, T5& param5, T6& param6,
            T7& param7, T8& param8, T9& param9, T10& param10, T11& param11)
    {
        int size = sizeof(T0) + sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5) + sizeof(T6) + sizeof(T7) + sizeof(T8) + sizeof(T9) + sizeof(T10) + sizeof(T11);

        uint8_t* buffer = new uint8_t[size];
        std::memset(&buffer[0], 0, size);

        uint32_t offset = 0;
        PushValue(buffer, param0, offset);
        PushValue(buffer, param1, offset);
        PushValue(buffer, param2, offset);
        PushValue(buffer, param3, offset);
        PushValue(buffer, param4, offset);
        PushValue(buffer, param5, offset);
        PushValue(buffer, param6, offset);
        PushValue(buffer, param7, offset);
        PushValue(buffer, param8, offset);
        PushValue(buffer, param9, offset);
        PushValue(buffer, param10, offset);
        PushValue(buffer, param11, offset);
        Send(aName, buffer, size);

        delete[] buffer;
    }

    template <typename T>
    void PushValue(uint8_t* buffer, T& value, uint32_t& offset)
    {
        std::memcpy(&buffer[offset], &value, sizeof(value));
        offset += sizeof(value);
    }
};

} // namespace SnobotSim

#endif // SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_BASEREVWRAPPER_H_

#ifndef IOHC_DEVICE_H
#define IOHC_DEVICE_H

#include <vector>
#include <iohcPacket.h>
#include <iohcRadio.h>

// #include <ArduinoJson.h>
// #include <LittleFS.h>

namespace IOHC {
    /* Base classe for all devices type */
    class iohcDevice {
        public:
            static iohcDevice *getInstance();
            virtual ~iohcDevice() = default;
            virtual bool isFake(address, address);
            virtual bool isHome(address, address);
            // void cmd(DeviceButton cmd, const char* data);

            bool verbosity{};

            virtual bool load() = 0;
            virtual bool save() = 0;
            // Memorize memorizeSend;

            virtual void scanDump() = 0;

            enum commandId {  
                DO_NOTHING                      = 0xFF,
                RECEIVED_WRITE_PRIVATE_0x20     = 0x20,         SEND_WRITE_PRIVATE_0x20     = 0x20,
                RECEIVED_PRIVATE_ACK_0x21       = 0x21,         SEND_PRIVATE_ACK_0x21       = 0x21,
                RECEIVED_DISCOVER_0x28          = 0x28,         SEND_DISCOVER_0x28          = 0x28,
                RECEIVED_DISCOVER_ANSWER_0x29   = 0x29,         SEND_DISCOVER_ANSWER_0x29   = 0x29,
                RECEIVED_DISCOVER_REMOTE_0x2A   = 0x2A,         SEND_DISCOVER_REMOTE_0x2A   = 0x2A,
                RECEIVED_DISCOVER_REMOTE_ANSWER_0x2B  = 0x2B,   SEND_DISCOVER_REMOTE_ANSWER_0x2B  = 0x2B,
                RECEIVED_DISCOVER_ACTUATOR_0x2C       = 0x2C,   SEND_DISCOVER_ACTUATOR_0x2C       = 0x2C,
                RECEIVED_DISCOVER_ACTUATOR_ACK_0x2D   = 0x2D,   SEND_DISCOVER_ACTUATOR_ACK_0x2D   = 0x2D,
                RECEIVED_UNKNOWN_0x2E           = 0x2E,         SEND_UNKNOWN_0x2E           = 0x2E,
                RECEIVED_ASK_CHALLENGE_0x31     = 0x31,         SEND_ASK_CHALLENGE_0x31     = 0x31,
                RECEIVED_KEY_TRANSFERT_0x32     = 0x32,         SEND_KEY_TRANSFERT_0x32     = 0x32,
                RECEIVED_KEY_TRANSFERT_ACK_0x33 = 0x33,         SEND_KEY_TRANSFERT_ACK_0x33 = 0x33,
                RECEIVED_ADDRESS_REQUEST_0x36   = 0x36,         SEND_ADDRESS_REQUEST_0x36   = 0x36,
                RECEIVED_LAUNCH_KEY_TRANSFERT_0x38  = 0x38,     SEND_LAUNCH_KEY_TRANSFERT_0x38  = 0x38,
                RECEIVED_CHALLENGE_REQUEST_0x3C     = 0x3c,     SEND_CHALLENGE_REQUEST_0x3C     = 0x3c,
                RECEIVED_CHALLENGE_ANSWER_0x3D      = 0x3d,     SEND_CHALLENGE_ANSWER_0x3D      = 0x3d,
                RECEIVED_GET_NAME_0x50          = 0x50,         SEND_GET_NAME_0x50          = 0x50,
                RECEIVED_ERROR_0xFE             = 0xfe,         SEND_ERROR_0xFE             = 0xfe,
            };

        private:
            // iohcCozyDevice2W();
            // static iohcCozyDevice2W *_iohcCozyDevice2W;

        protected:
            // address _node;
            // uint16_t _sequence;
            // uint8_t _key[16];
            // std::vector<uint16_t> _type;
            // uint8_t _manufacturer;
            bool Fake = false;
            bool Home = false;

//            iohcPacket *packets2send[25]{};
            // std::array<iohcPacket*, 25> packets2send{};
            std::vector<iohcPacket*> packets2send{};
            iohcRadio *_radioInstance{};
    };
}
#endif
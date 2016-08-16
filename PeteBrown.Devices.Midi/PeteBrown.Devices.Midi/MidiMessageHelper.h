#pragma once

namespace PeteBrown
{
    namespace Devices
    {

        // This is not yet implemented, and so is private for now.

        namespace Midi
        {
            public ref class MidiMessageHelper sealed
            {
            private:
				// MIDI message numbers for NRPN
				static const byte NRPN_PARAMETER_MSB = 99;
				static const byte NRPN_PARAMETER_LSB = 98;
				static const byte NRPN_VALUE_MSB = 6;
				static const byte NRPN_VALUE_LSB = 38;
				static const byte NRPN_PARAMETER_NUMBER_NULL = 127;	// value to be sent as parameter number after done

				// MIDI message numbers for RPN
				static const byte RPN_PARAMETER_MSB = 101;
				static const byte RPN_PARAMETER_LSB = 100;
				static const byte RPN_VALUE_MSB = 6;
				static const byte RPN_VALUE_LSB = 38;
				static const byte RPN_PARAMETER_NUMBER_NULL = 127;		// value to be sent as parameter number after done


                MidiMessageHelper();

                inline static byte msb(unsigned short value) { return (value >> 7) & 0x7F; }
                inline static byte lsb(unsigned short value) { return value & 0x7F;	}
                inline static byte BuildMidiStatusByte(byte message, byte channel) { return message << 4 | channel; }

            public:		
				/// <summary>
				/// Send a Non-Registered Parameter Number Message. These messages vary by manufacturer.
				/// If you are immediately following this message with other values for the same parameter, pass a false value for sendNullClosing. 
				/// </summary>
				static void SendNrpnMessage(Windows::Devices::Midi::MidiOutPort^ outputPort, byte channel, unsigned short parameterNumber, unsigned short parameterValue, bool sendNullClosing);
				inline static void SendNrpnMessage(Windows::Devices::Midi::MidiOutPort^ outputPort, byte channel, unsigned short parameterNumber, unsigned short parameterValue)
				{
					SendNrpnMessage(outputPort, channel, parameterNumber, parameterValue, true);
				}

				/// <summary>
				/// Send a Registered Parameter Number Message. These messages are standardized.
				/// If you are immediately following this message with other values for the same parameter, pass a false value for sendNullClosing. 
				/// </summary>
				static void SendRpnMessage(Windows::Devices::Midi::MidiOutPort^ outputPort, byte channel, unsigned short parameterNumber, unsigned short parameterValue, bool sendNullClosing);
				inline static void SendRpnMessage(Windows::Devices::Midi::MidiOutPort^ outputPort, byte channel, unsigned short parameterNumber, unsigned short parameterValue)
				{
					SendRpnMessage(outputPort, channel, parameterNumber, parameterValue, true);
				}

            };
        };
    };
};


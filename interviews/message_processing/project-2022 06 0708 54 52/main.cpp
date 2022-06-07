#include <iostream> 
#include <vector>

/*
 * Obsługa wiadomości.
 * Założenia i cele:
 * - kod powinien być łatwo rozszerzalny o nowe wiadomości,
 * - kod powinien być otestowany - testy zawrzyj w funkcji main w odpowiednich blokach opisanych
 *   jako "Scenariusz X" - jeśli potrzeba, dodaj kolejny blok. Każdy test powinien być
 *   nazwany (nazwy pisz jako komentarz do testu poniżej). Nazwy testów są częścią kodu,
 *   dlatego pisz je po angielsku oraz nie używaj spacji (traktuj je jak kod źródłowy).
 * - kod powinien być łatwo testowalny poprzez testy jednostkowe. Testy powinny być proste
 *   i przejrzyste,
 *
 * Zadania:
 * 1. Zaimplementuj dekoder wiadomości dla warstwy transportowej.
 * 2. Zaimplementuj filtrację adresów sender / receiver. Niech dany odbiorca przyjmuje wiadomości
 *    tylko od zarejestrowanych adresów "sender'a". Przyjmuje się, że adres "sender" 0x01
 *    jest adresem prawidłowym (obsługiwanym). Wiadomości z innymi adresami powinny być
 *    odrzucane.
 * 3. Zaimplementuj dekoder wiadomości dla warstwy aplikacyjnej.
 * 4. Zaimplementuj obsługę dla różnych wiadomości (Msg ID).
 * 5. Dodaj nową wiadomość o ID 2
 */

using Msg = std::vector<std::uint8_t>;

/*
 * Format wiadomości:
 * |  Transport Layer  |                   Application Layer                |
 * |   1B   |    2B    |                 3B                       |   x B   |
 * | Sender | Receiver | Msg ID (3 bits) |  Payload size (5 bits) | Payload |
 */
void receive(const Msg& msg)
{
}
 
int main()
{
    // decode_addresses
    {
        std::vector<std::uint8_t> msg{
            0x01, 0x02, 0x05, 0x48, 0x65, 0x6C, 0x6C, 0x6F
        };
        constexpr std::uint8_t expectedSenderAddress{0x01};
        receive(msg);
    }

    // Scenariusz 2
    {
        std::vector<std::uint8_t> msg{
            0x03, 0x02, 0x05, 0x48, 0x65, 0x6C, 0x6C, 0x6F
        };
        receive(msg);
    }

    // Scenariusz 3
    {
        std::vector<std::uint8_t> msg{
            0x01, 0x02, 0x35, 0x42, 0x79, 0x65
        };
        receive(msg);
    }

    // Scenariusz 4
    {
        std::vector<std::uint8_t> msg{
            0x03, 0x02, 0x35, 0x42, 0x79, 0x65
        };
        receive(msg);
    }
}
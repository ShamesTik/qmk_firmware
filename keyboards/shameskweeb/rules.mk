# MCU name
MCU = STM32F411
BOARD = BLACKPILL_STM32_F411

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no 		# Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
KEYBOARD_SHARED_EP = yes    # Free up some extra endpoints - needed if console+mouse+extra
ENCODER_ENABLE = yes        # Enable Rotary Encoder

TAP_DANCE_ENABLE = yes
KEY_LOCK_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
WPM_ENABLE = yes

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

UNICODEMAP_ENABLE = yes
# LTO_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk

SRC += features/mouse_turbo_click.c
DEFERRED_EXEC_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = yes
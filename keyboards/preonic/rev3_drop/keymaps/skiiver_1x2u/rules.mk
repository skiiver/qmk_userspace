#SRC += muse.c # removed for space savings; we don't need music

# Note only need to add if overruling defaults in /planck/rev6/rules.mk
BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration, large storage
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no       # Commands for debug and configuration
AUDIO_ENABLE = no           # Audio output

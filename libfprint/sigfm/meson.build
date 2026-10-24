
sigfm_sources = ['sigfm.cpp']

opencv = dependency('opencv4', required: true)
doctest = dependency('doctest', required: false, version: ['>=2.0.0', '<3.0.0'])

libsigfm = static_library('sigfm',
        sigfm_sources,
        dependencies: [opencv],
)

# doctest ships header-only with no pkg-config file on some distros; only build
# the unit tests when it is actually available so the library still configures.
if doctest.found()
        sigfm_tests = executable('sigfm-tests', ['./tests.cpp'], dependencies: [doctest, opencv], link_with: [libsigfm])
endif

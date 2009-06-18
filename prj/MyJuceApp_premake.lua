project.name = "MyJuceApp"
project.bindir = "../bin"
project.libdir = "../lib"

project.configs = { "Debug", "Release" }

package = newpackage()
package.name = "MyJuceApp"
package.kind = "winexe"
package.language = "c++"

package.files = { matchfiles (
    "../src/*.h",
    "../src/*.cpp"
    )
}

package.includepaths = {
    "../../MyLib/build",
    "../../MyLib/juce",
    "../../MyLib/include",
    "/usr/include",
}

package.libpaths = {
    "../../MyLib/bin",
    "../../MyLib/lib",
    "../../MyLib/juce/bin",
    "/usr/lib",
}

package.config["Debug"].objdir   = "Debug"
package.config["Release"].objdir = "Release"

package.config["Debug"].target   = "MyJuceAppD"
package.config["Release"].target = "MyJuceApp"

package.defines                   = { "LINUX" };
package.config["Debug"].defines   = { "DEBUG", "_DEBUG" };
package.config["Release"].defines = { "NDEBUG" };

package.buildflags                   = { "extra-warnings" }
package.config["Debug"].buildoptions = { "-ggdb" }

package.links = { "GL", "GLU", "Xxf86vm", "Xinerama", "pthread", "freetype" }
package.config["Debug"].links = { "tcpd", "traced", "juce_debug" }
package.config["Release"].links = { "tcp", "trace", "juce" }

package.linkflags = { "static-runtime" }

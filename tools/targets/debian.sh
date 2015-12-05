BUILD_DEPS=`awk 'BEGIN {cnt = 1;} /^Build-Depends:/ {split($0, line, ":");split(line[2], deps, ",");for (i in deps) {d = deps[i];sub(/^ */, "", d);sub(/ *$/, "", d);split(d, tokens, " ");packages[cnt] = tokens[1];cnt++;}} END {out = ""; for(i = 1; i <= cnt; i++) {out = out packages[i] " ";} print out; }' debian/control`
CHANGELOG=debian/changelog
NOW=`date -R`
#VER=`git describe | sed "s/\([0-9]*\)\.\([0-9]*\)-\([0-9]*\)-.*/\1.\2.\3/"`
VER=`cat VERSION`
TANO_EXPORT_BRANDING="-DBRANDING=${CUSTOM}"
[ -z "${DEBDIST:-}" ] && DEBDIST="unstable"
[ -z "${DEBSUFFIX:-}" ] && DEBSUFFIX=""

build() 
{
    if [ "${CUSTOM}" != "" ]; then
        echo "Branded build: ${CUSTOM}"

        VER=`cat src/branding/${CUSTOM}/VERSION`
        cp -r src/branding/${CUSTOM}/debian/ .

        export TANO_EXPORT_BRANDING

        echo >${CHANGELOG} "`echo ${CUSTOM} | awk '{print tolower($0)}'` (${VER}-${BUILD}${DEBSUFFIX}) ${DEBDIST}; urgency=low"
    else
        echo >${CHANGELOG} "tano (${VER}-${BUILD}${DEBSUFFIX}) ${DEBDIST}; urgency=low"
    fi

    echo >>${CHANGELOG}
    echo >>${CHANGELOG} "  * The full changelog can be found in NEWS"
    echo >>${CHANGELOG} "    or by running 'git log' when using Git"
    echo >>${CHANGELOG}
    echo >>${CHANGELOG} " -- Tadej Novak <tadej@tano.si>  ${NOW}"

    dpkg-buildpackage -b -us -uc ${DEVEL}

    git clean debian/ -fdx || { echo "Git is not installed. Debian directory will not be cleaned."; }
    git checkout debian/ || { echo "Git is not installed. Debian directory will not be cleaned."; }

    echo "Completed!"
}

deps() 
{
    if [[ $EUID -ne 0 ]]; then
	echo "Build dependencies must be installed as root"
	exit 1
    fi
    apt-get -y install ${BUILD_DEPS}
}

eval build

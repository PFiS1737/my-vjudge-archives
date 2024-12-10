set shell := ["fish", "-c"]

default:
    @just config debug build then run

then:
    @echo

config mode:
    @xmake config -m {{mode}}

build:
    @xmake build

run:
    @xmake run

checkout id='':
    @./scripts/checkout {{id}}

judge:
    @./scripts/judge

clean:
    @xmake clean

distclean:
    @rm -rf ./build
    @rm -rf ./.xmake
    @rm -rf ./.cache

local nsense = require "nsense"

nsense.makescene(10, 15)
nsense.makerec(4, 5)
nsense.add2scene(1, 1, 15)
nsense.addscript("foo.lua")
nsense.run()

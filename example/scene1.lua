scene1 = {}

local up = true

scene1.Init = function()
	nsense.makerec("r1", 4, 5)
	nsense.put("r1", 3, 4)
end

scene1.Update = function()
	local r1left, r1top = nsense.position("r1")
	if r1top == 1 then
		up = false
	end
	if r1top + 5 == scene1height then
		up = true
	end
	if up then
		nsense.moveup("r1", 1)
	else
		nsense.movedown("r1", 1)
	end
end

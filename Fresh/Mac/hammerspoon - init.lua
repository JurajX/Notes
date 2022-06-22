-- window management
hs.fnutils.each({
        { key = 'pageup',   unit_half = {0  , 0  , 1  , 0.5}, unit_quarter = {0.5, 0  , 0.5, 0.5} },
        { key = 'pagedown', unit_half = {0  , 0.5, 1  , 0.5}, unit_quarter = {0  , 0.5, 0.5, 0.5} },
        { key = 'home',     unit_half = {0  , 0  , 0.5, 1  }, unit_quarter = {0  , 0  , 0.5, 0.5} },
        { key = 'end',      unit_half = {0.5, 0  , 0.5, 1  }, unit_quarter = {0.5, 0.5, 0.5, 0.5} }
    },
    function(object)
        -- half screen window management
        hs.hotkey.bind({
            'cmd' },
            object.key,
            function() hs.window.focusedWindow():moveToUnit(object.unit_half)
            end
        )
        -- quarter screen window management
        hs.hotkey.bind({
            'cmd', 'option' },
            object.key,
            function() hs.window.focusedWindow():moveToUnit(object.unit_quarter)
            end
        )
    end
)

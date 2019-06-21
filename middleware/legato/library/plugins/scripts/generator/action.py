def generateCustomAction(file, scr, action):
    file.write("    // %s : %s - %s", action.name, action.prettyName, action.description)

    lines = action.code.split('\r?\n')

    if len(lines) > 0:
        for line in lines:
            file.write("    %s", line)

def generateTemplateAction(file, screen, owner, origin, action):
    i = 0


def generateAction(file, scr, owner, origin, action):
    if action.type == "template":
        generateTemplateAction(file, scr, owner, origin, action)
    else:
        generateCustomAction(file, scr, action)

    file.write('')
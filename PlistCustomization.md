Dimelo Plist configuration
==========================

All keys are optional.

[Download example plist](https://raw.githubusercontent.com/dimelo/Dimelo-iOS/master/Dimelo/DimeloConfig.plist?token=AAAerlawQARBQ6TV9UhaL6FzBKNpsC02ks5VAJLlwA%3D%3D).

### apiKey
Public API key that identifies all requests to Dimelo (used only for the
secure server-side authentication, see section "Setup with a server-side secret")

API Key is always represented in hex format, e.g. `ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70`.

### apiSecret
Secret API key, only embed in the app for client-side authentication, see section "Setup with a built-in secret").
This is not recommended to embed in .plist but rather to set it directly via a setter in the code of the application for better obfuscation.

API Key is always represented in hex format, e.g. `ab12d1a2a9349797b807589e7e1635cb760d69de3a8241070b1682a1bdbd6d70`.

### title
Title of the conversation window. 

This will be used as an argument to NSLocalizedString.

### tintColor
Tint color for aux controls: Close button, Send button, cursor etc.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### navigationBarTintColor
Bar tint color for navigation bar (sets `barTintColor` property).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### navigationBarColor
Background color for navigation bar (sets `backgroundColor` property).

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### userMessageTextColor
Foreground color for user's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### agentMessageTextColor
Foreground color for agent's message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### systemMessageTextColor
Foreground color for system notification message text.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### userMessageBackgroundColor
Background color for user message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### agentMessageBackgroundColor
Background color for agent message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### systemMessageBackgroundColor
Background color for system message bubbles.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### dateTextColor
Text color for the date label.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### agentNameColor
Text color for agent's name.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### loadMoreMessagesButtonTextColor
Text color for the button "load more messages".

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### inputBarTintColor
Bar tint color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### inputBarBackgroundColor
Background color of the input bar.

Color must be in hex format, e.g. `007AFF` or `#007AFF`.

### messageFont
Font for user and agent messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

### systemMessageFont
Font for system messages.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`. 
E.g. `name=HelveticaNeue-Regular` and `size=15`.

### dateFont
Font for the date label.

Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

### agentNameFont
Font for agent's name.
Must contain a dictionary with `name` and `size` keys.
These values will be used as arguments to `+[UIFont fontWithName:size:]`.
E.g. `name=HelveticaNeue-Regular` and `size=15`.

Follow these steps to generate p12 or p8 file for push notification:

Generate p12 certificate
------------------------

Create an App ID
----------------

1. In your developer account, go to Certificates, Identifiers & Profiles.
2. Under Identifiers, select App IDs and create a new App ID.
<p align="center">
<img src="https://i.postimg.cc/dtPWh6k8/image.png"/>
</p>

3. Specify **App name, Bundle ID** and select **Push Notifications**, then Continue
<p align="center">
<img src="https://i.postimg.cc/LsbD23Fg/image.png"/>
</p>

4. Click Register, then Done to complete app registration
<p align="center">
<img src="https://i.postimg.cc/VvyFbs6Y/image.png"/>
</p>

5. Now, you can see the app listed in App IDs
<p align="center">
<img src="https://i.postimg.cc/SxQf9vyz/image.png"/>
</p>


Generate a Certificate from Keychain Access
-------------------------------------------

1. Launch the Keychain Access application in your Mac OS X and Select Keychain Access -> Certificate Assistant -> Request a Certificate From a Certificate Authority
<p align="center">
<img src="https://i.postimg.cc/59wBRVyC/image.png"/>
</p>

2. Enter email address and check the ‘Saved to disk’ option, then click Continue
<p align="center">
<img src="https://i.postimg.cc/VvBXrjpR/image.png"/>
</p>

3. Save certificate
<p align="center">
<img src="https://i.postimg.cc/GpHP7TTL/image.png"/>
</p>

Generate a Development Certificate
----------------------------------

1. **Go back to developer account** and select app from App IDs and click **Edit**
<p align="center">
<img src="https://i.postimg.cc/tgTkKmwH/image.png"/>
</p>

2. Scroll Down to Development SSL certificates and click Create Certificate
<p align="center">
<img src="https://i.postimg.cc/50Q30Qf7/image.png"/>
</p>

3. Click Continue
<p align="center">
<img src="https://i.postimg.cc/J45QGLWL/image.png"/>
</p>

4. **Choose certificate file created from Keychain Access** in previous section and click **Continue**
<p align="center">
<img src="https://i.postimg.cc/85vRD8bx/image.png"/>
</p>

5. Download Development Certificate and click Done to finish process
<p align="center">
<img src="https://i.postimg.cc/gkmV9TLB/image.png"/>
</p>

Generate APNS .p12 certificate
------------------------------

1. Double click Development certificate generated in previous step to add it to Keychain Access. Go to Keychain Access, select **login keychain** and **My Certificate** from side menu. Find app certificate and **right click to export it**
<p align="center">
<img src="https://i.postimg.cc/d1NbMy45/image.png"/>
</p>

2. Enter certificate name and click Save
<p align="center">
<img src="https://i.postimg.cc/fLRGgKj3/image.png"/>
</p>

3. Enter **password** for certificate and click **OK**
<p align="center">
<img src="https://i.postimg.cc/cLGVNZBG/image.png"/>
</p>

This development .p12 certificate can be used to send push notification.


Generate p8 certificate
-----------------------

Create the p8 file and get the Key ID
-------------------------------------

<p align="center">
<img src="https://i.postimg.cc/dtCGyKP1/image.png"/>
</p>

1. In your developer account, go to Certificates, Identifiers & Profiles.
2. Under Keys, select All and click the Add button (+) in the upper-right corner.
3. Under Key Description, enter a unique name for the signing key.
4.	Under Key Services, select the APNs checkbox, then click Continue.
<p align="center">
<img src="https://i.postimg.cc/tRwhJ4cw/image.png"/>
</p>

5.	Review the key configuration, then click Confirm.
6.	Click Download to generate and download the key now.
If you download the key, it is saved as a text file with a .p8 file extension. Save the file in a secure place because the key is not saved in your developer account and you won’t be able to download it again.

Get the Team ID
---------------

<p align="center">
<img src="https://i.postimg.cc/XJ7wG29Y/image.png"/>
</p>

1. In your developer account, go to Membership.
2. Get the Team ID.

